#include <iostream>
#include <cstring>

using namespace std;


bool query();
int sort


int main(){
  query();
  
  
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
