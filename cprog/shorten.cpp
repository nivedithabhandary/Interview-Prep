#include<iostream>
#include<string>
using namespace std;

string shorten(string s) {
  string result = "";
  int count = 0;
  for(int i=0; i<s.length(); i++) {
    if(s[i] == s[i+1]) {
      count++;
    } else {
      result += s[i];
      result += to_string(count+1);
      count = 0;
    }
  }
  return result;
}

int main() {
  string result = shorten("aaaabbbbcccnnndsk");
  cout<<result<<endl;


}
