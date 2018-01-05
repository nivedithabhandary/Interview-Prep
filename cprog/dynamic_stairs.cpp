#include<iostream>
using namespace std;

int countWays(int n) {

  int *memo = new int[n];

  memo[0] = 0;
  memo[1] = 1;
  memo[2] = 2;

  for(int i=3; i<=n; i++) {
    memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
  }
  return memo[n];


}

int main() {
  int num_steps = 41;
  cout<<"Number of ways of climbing : "<<countWays(num_steps)<<endl;
}
