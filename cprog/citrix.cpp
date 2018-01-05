
#include <iostream>
using namespace std;

int parseInt(string input) {

  int result = 0;
  int op = 1;

  for(int i=0; i<input.size(); i++) {
    if(input[i] == '-') {
      op = -1;
      continue;
    } else if(input[i] == '+') {
      continue;
    }
    int num = input[i] - '0';
    if(num > 9) {
      cout<<"Exception: Invalid Input!"<<endl;
      exit(1);
      //return -1;
    }
    result = result*10 + num;
  }

  return result * op;
}

int main() {

  string str = "+43";
  cout<<"Result : "<<parseInt(str)<<endl;
}
