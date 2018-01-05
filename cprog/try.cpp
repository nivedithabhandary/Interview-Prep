#include <iostream>
using namespace std;

int arrangeCoins(int n) {
    int sum = n, i=0;
    if(sum==0) {
        return 0;
    }
    while (sum > 0) {
        i++;
        sum = sum - i;
    }
    if(sum==0) {
        return i;
    } else {
        return i-1;
    }
}

int main() {

  int x=5;
  cout<<"Number of levels : "<<arrangeCoins(x)<<endl;
}
