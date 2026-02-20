#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


bool query();
int sort(int count, ifstream& f, int array[]){//do i make int array[100]?
  f >> array[count];
  return array[100];
}

int main(){
  int array[100];
  int num;
  query();
  if (query){
    int count = 1;
    ifstream f("nums.txt");
    while(count < 101 && f){
      sort(count, f, array);//[100]);
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
