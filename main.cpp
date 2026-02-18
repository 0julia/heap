#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


bool query();
int sort(int num, int array[]);//do i make int array[100]?


int main(){
  int array[100];
  int num;
  query();
  if (query){
    int count;
    fstream f("nums.txt");
    while(count < 100 && f >> array[count]){
      
      count++;
    }
    for(int i=1;i<100;i++){
      
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
