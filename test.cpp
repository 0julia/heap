#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;


struct Sort{
  void firstSpot(int count, int num, int array[]){//reconsider returntype
    array[count] = num;
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

char query();
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
   cout << "Type 'f' to input file, 'a' to manually add number, 'd' to delete la\
rgest number, 'r' to remove all, 'p' to print, or 'q' to quit. " << endl << endl;

  Sort s;
  int array[100];
  int count = 1;
  char ask = query();
  int num;
  while(ask != 'q'){
    if (ask == 'f'){
	ifstream f("nums.txt");
      while(count < 101 && f){
	f >> num;
	s.firstSpot(count, num, array);
	count++;
      }
    } else if(ask == 'a'){
      while(num != -1){
	cout << "What number would you like to add? (type '-1' to quit) ";
	cin >> num;
	if(num != -1){
	  s.firstSpot(count, num, array);
	  count++;
	}
      }
      num = 0;      
    } else if(ask == 'd'){
      cout << "now delete" << endl;
    } else if(ask == 'r'){
      cout << "now remove all" << endl;
    } else if(ask == 'p'){
      printTree(array, count, 1, 0);
    }

    ask = query();
  }
  return 0;
}


char query(){
  
  char ask;
  cout << endl << "What would you like to do? ";
  cin >> ask;
  cout << endl;
  if (ask == 'f'){
    return 'f';
  } else if (ask == 'a'){
    return 'a';
  } else if(ask == 'd'){
    return 'd';
  }else if(ask == 'r'){
    return 'r';
  }else if(ask == 'p'){
    return 'p';
  }else if(ask == 'q'){
    return 'q';
  }else{
    cout << "That is not a valid command" << endl << "Type 'f' to input file, '\
a' to manually add number, 'd' to delete largest number, 'r' to remove all, 'p'\
 to print, or 'q' to quit. ";
    query();
  }

  /*
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
  */
  return false;
}
