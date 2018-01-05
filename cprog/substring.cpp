#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_subsequences(string s) {
    
    vector<string> substr_s;
    int len = s.length();
    for(int i=0; i<len; i++) {
        for(int j=1; j<=len-i; j++) {
            substr_s.push_back(s.substr(i, j));
        }
    }

    for(int i=0; i<substr_s.size(); i++) {
        cout<<substr_s[i]<<"\n";
    }
}


int main() {
    string test = "abc";
    print_subsequences(test);
}
