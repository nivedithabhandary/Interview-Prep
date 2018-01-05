#include <iostream>
using namespace std;

int main() {

    int A[4] = {1,2,2,4};

    int result;

    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++) {
        cout<<"before xor : " <<result;
        result = result ^ A[i];
        cout<<"after xor : "<<result;
    }
    cout<<result<<endl;

}
