#include<iostream>
#include<string>
using namespace std;

bool unique_chars(string s){
    int checker = 0;
    for(int i=0; i<s.length(); i++) {
        int temp = s[i]-'a';
        if((checker & 1<<temp) > 0) return false;
        checker |= (1<<temp);
    }
    return true;
}

string remove_duplicates(string s) {
    int buffer[256];
    string result = "";
    for(int i=0; i<256; i++) {
        buffer[i] = 0;
    }
    for(int j=0; j<s.length(); j++) {
        int temp = s[j]-'a';
        if(buffer[temp]==0){
            buffer[temp] = 1;
            result += s[j];
        } else {
            buffer[temp]++;
        }
    }
    return result;
}

bool are_anagrams(string s, string t) {
    int len1 = s.length(), len2=t.length();
    if(len1!=len2) {
        return false;
    }

    int buffer[256];


}
int main(){
    cout<<unique_chars("sssssjdkdkjskfj")<<endl;
    cout<<unique_chars("asdflkjh")<<endl;

    cout<<remove_duplicates("aaaaa")<<endl;
    cout<<remove_duplicates("abcd")<<endl;
    cout<<remove_duplicates("")<<endl;
    cout<<remove_duplicates("aaaaabbbb")<<endl;
    cout<<remove_duplicates("ababab")<<endl;
}
