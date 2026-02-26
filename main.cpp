#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;


struct Sort{
  void firstSpot(int count, ifstream& f, int array[]){//reconsider returntype
    f >> array[count];
    while(count != 1 && needSwap(array, count) == true){
      //cout << "hmm";
      count = swap(count, array); //
    }
  }
  
  bool needSwap(int array[], int count){
    //check if child is bigger than parent
    bool tf = false;
    if (array[count] > array[count/2]){
      //cout << "Parent: " << array[count/2] << " Child: " << array[count] << endl;
      tf = true;
    }
    return tf;
  }
  int swap(int count, int array[]){//return new index
    //swap parent and child
    int tempvar=array[count/2];
    array[count/2] = array[count];
    array[count] = tempvar;
    return (count/2);
  }
};

bool query();
void printTree(int array[], int lastIndex, int curIndex, int depth){
  if((curIndex*2)+1 < lastIndex){
    printTree(array, lastIndex, (curIndex*2)+1, depth+1);
  }
  for(int i=0; i<depth;i++){
    cout << "\t";
  }
  cout << array[curIndex]<< endl;
  if((curIndex*2) < lastIndex){
    printTree(array, lastIndex, (curIndex*2), depth+1);
  }
  
}

int main(){
  Sort s;
  int array[100];
  query();
  int count = 1;
  int num;
  if (query){
    ifstream f("nums.txt");
    while(count < 101 && f){
      s.firstSpot(count, f, array);//[100]);
      //f >> array[count];//this is how you insert the num
      count++;
    }
  } else{
    
    cout << "What number would you like to add? ";
    cin >> num;
    array[count] = num;
    count++;
    }

  printTree(array, count, 1, 0);
  return 0;
}


bool query(){
  char ask;
  cout << "Are you putting in a file? (type 'y' or 'n') ";
  cin >> ask;
  if (ask == 'y'){
    return true;
  } else if (ask == 'n'){
    return false;
  }else{
    cout << "That is not a valid command" << endl;
    query();
  }
  
  return false;
}
