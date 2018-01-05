#include<iostream>
using namespace std;

int fib(int n) {
  int * memo = new int[n];
  memo[0] = 0;
  memo[1] = 1;
  for(int i=2; i<n; i++) {
    memo[i] = memo[i-1] + memo[i-2];
  }

  return memo[n-1] + memo[n-2];
}

int main(int argc, char *argv[]){

  int n = 0;
  if(argc>1) {
    n = atoi(argv[1]);
  } else {
    cout<<"Enter value!";
    exit(1);
  }
  cout<<"FIb of n = "<<n<<" is : "<<fib(n);

}
