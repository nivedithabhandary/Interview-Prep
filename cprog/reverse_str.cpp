#include<iostream>
using namespace std;

char *reverse_string(char *s) {
    char *res;
    int l = 0;
    int r = strlen(s)-1;
    while(l<r) {    
        if(!is_alphabet(s[l])) {
            l++;
        }
        else if(!is_alphabet(s[r])) {
            r--;
        }
        else {
            
        }


        
    }

}

int main() {
    char *str = "a,b$c";
    cout<<"Reversed version of "<<str<<"is :"<<reverse_string(str)

}
