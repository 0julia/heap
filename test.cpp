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

  //deletes the biggest thing/head
  void deleteLargest(int array[], int &count){
    int index=1;//where the removed  thing is
    cout << array[1] << endl;
    array[index] = array[count];//replace the head with the last thing in the array
    while (index*2 <= count) {//so long as it has at least 1 child...
      if(array[index] < array[index*2] || array[index] < array[index*2+1]){//and the child is bigger than it...
	if (array[index*2] < array[index*2+1]){ //and if right is larger than left
	  index = (swap(index*2+1, array))*2+1; //swap parent and child
	} else if(array[index*2] > array[index*2+1]){ // if left is bigger than right
	  index = 2*swap(index*2, array);//swap parent and child
	}else{
	  break; // safety net
	}
      }else{
	break;
      }
    }
    array[count] = 0; //get rid of last thing in array (moved to head)
    count--;//get rid of last thing
  }
};

char query();
void printTree(int array[], int lastIndex, int curIndex, int depth){//PRINT!!!
  if((curIndex*2)+1 < lastIndex){//as long as this index isn't at the end (right child)
    printTree(array, lastIndex, (curIndex*2)+1, depth+1); //recurssive
  }
  for(int i=0; i<depth;i++){ // make spaces
    cout << "\t";
  }
  cout << array[curIndex]<< endl; //print child
  if((curIndex*2) < lastIndex){ // as long as index isn't at end (wrong child)
    printTree(array, lastIndex, (curIndex*2), depth+1); //recurssive
  }
  
}

int main(){
  //rules
   cout << "Type 'f' to input file, 'a' to manually add number, 'd' to delete la\
rgest number, 'r' to remove all, 'p' to print, or 'q' to quit. " << endl << endl;

  Sort s;
  int array[100]; //he said max is 100 ints
  int count = 0;
  char ask = query(); //print, quit, delete all, delete head,add, add from text file
  int num;
  while(ask != 'q'){
    if (ask == 'f'){ //add from text file
      ifstream f("text.txt");
      while(count < 101 && f>> num){
	count++;
	s.firstSpot(count, num, array);
      }
    } else if(ask == 'a'){//manual ask, keeps on going till person stops it
      while(num != -1){
	cout << "What number would you like to add? (type '-1' to quit) ";
	cin >> num;
	if(num != -1){
	  count++;
	  s.firstSpot(count, num, array);
	}
      }
      num = 0; //resets so doesn't start at -1
    } else if(ask == 'd'){//delete head
      s.deleteLargest(array, count);
    } else if(ask == 'r'){//delete for all things
      cout << "now remove all" << endl;
      while(count >= 1){//print
	s.deleteLargest(array,count);
      }
    } else if(ask == 'p'){
      printTree(array, count+1, 1, 0);
    }

    ask = query();
  }
  cout << "I really wanted to do a for loop printing the same thing ~ 1 billion times so ud think theres an infanite loop, but I didn't. Your welcome!";
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
