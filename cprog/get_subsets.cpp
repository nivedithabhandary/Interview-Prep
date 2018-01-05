#include<iostream>
using namespace std;

int arr[3];
void get_all_subsets(int n) {
    if(n==0) {
        for(int i=0; i<3; i++) {
            cout<<arr[i]<<"\t";
        }
        cout<<"\n";
        return;
    }
    arr[n-1] = 0;
    get_all_subsets(n-1);
    arr[n-1] = 1;
    get_all_subsets(n-1);
}

int main() {
    int n=3;
    get_all_subsets(n);
}
