#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;

void printTree(int array[],int num, int othernum, int lastnum);
struct Sort{
  void firstSpot(int count, int num, int array[]){ //puts the num at the end of the array
    array[count] = num;
    while(count != 1 && needSwap(array, count) == true){ // then considers swapping
      count = swap(count, array);
    }
  }
  
  bool needSwap(int array[], int count){ //check if needs swapping
    //check if child is bigger than parent
    bool tf = false;
    if (array[count] > array[count/2]){
      tf = true;
    }
    return tf; //if needSwap is true, then will swap
  }
  int swap(int count, int array[]){//moves parent item to child then return new child index
    //swap parent and child
    int tempvar=array[count/2];
    array[count/2] = array[count];
    array[count] = tempvar;
    return (count/2);
  }

	
  void deleteLargest(int array[], int count){
    int index=1;//where the removed  thing is
    cout << array[1] << endl;
    bool stillGoing = true;
    array[index] = array[count];
    while (array[index] < array[index*2] || array[index] < array[index*2+1]){
      if (array[index*2] < array[index*2+1]){ //if right is larger than left
	index = (swap(index*2+1, array))*2+1;
      } else if(array[index*2] > array[index*2+1]){ // if left is bigger than right
	index = 2*swap(index*2, array);
      }
    }
    count--;
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
  int count = 0;
  char ask = query();
  int num;
  while(ask != 'q'){
    if (ask == 'f'){
      ifstream f("nums.txt");
      while(count < 101 && f>> num){
	cout << num << " ";
	count++;
	s.firstSpot(count, num, array);
      }
    } else if(ask == 'a'){
      while(num != -1){
	cout << "What number would you like to add? (type '-1' to quit) ";
	cin >> num;
	if(num != -1){
	  count++;
	  s.firstSpot(count, num, array);
	}
      }
      num = 0;      
    } else if(ask == 'd'){
      cout << "count: " << count << endl;
      s.deleteLargest(array, count);
      count--;
    } else if(ask == 'r'){
      cout << "now remove all" << endl;
      for(int i = 1; i <=count; i++){
	s.deleteLargest(array,count);
	count--;
      }
    } else if(ask == 'p'){
      printTree(array, count+1, 1, 0);
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

  return false;
}
