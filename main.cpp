#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;


struct Sort{
  int firstSpot(int count, ifstream& f, int array[]){//reconsider returntype
    f >> array[count];
    while(count != 1 && needSwap(array, count) == true){
      count = swap(array, count); //
    }
    return array[100];
  }
  bool needSwap(int array[], int count){
    //check if child is bigger than parent
    bool tf = false;
    if (array[count] > array[count/2]){
      cout << "Parent: " << array[count/2] << " Child: " << array[count] << endl;
      tf = true;
    }
    return tf;
  }
  int swap(){//return new index
    //swap parent and child
    return 0;
  }
};

bool query();


int main(){
  Sort s;
  int array[100];
  int num;
  query();
  if (query){
    int count = 1;
    ifstream f("nums.txt");
    while(count < 101 && f){
      s.firstSpot(count, f, array);//[100]);
      //f >> array[count];//this is how you insert the num
      count++;
    }
    for(int i=1;i<101;i++){
      
      cout << array[i]<<endl;
    }
  }
  
  
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
