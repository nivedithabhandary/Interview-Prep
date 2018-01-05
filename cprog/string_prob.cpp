#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;

bool isAnagram(string s1, string s2) {
  vector<int> hash_table(256,0);

  for(int i=0; i<s1.length(); i++) {
    hash_table[s1[i]]++;
  }

  for(int i=0; i<s2.length(); i++) {
    hash_table[s2[i]]--;
  }

  for(int i=0; i<256; i++) {
    if(hash_table[i]!=0) {
      return false;
    }
  }

  return true;
}

string reverse_string(string s1) {
  if(s1.length()==0) {
    return "";
  }
  char first = s1[0];
  string rem = s1.substr(1,s1.length());
  return reverse_string(rem) + first;
}

/*void get_anagrams(string s1, vector<string>& res) {


  char first = s1[0];
  string rem = s1.substr(1,s1.length());

  get_anagrams(rem, int)

}*/

int convert_to_int(const char *s, int len) {
  int result = atoi(&s[0]);
  for(int i=1; i<len; i++) {
    if(!isdigit(s[i])) {
      char ch = s[i];
      switch(ch) {
        case '+' : result = result + atoi(&s[i+1]);
                   break;
        case '-' : result = result - atoi(&s[i+1]);
                   break;
        case '*' : result = result * atoi(&s[i+1]);
                   break;
        case '/' : result = result / atoi(&s[i+1]);
                   break;
      }
    }
  }
  return result;
}

int main()
{
  string str1 = "abc";
  string str2 = "cab";

  const char * str3 = "1+2-3*4";
  int len = strlen(str3);

  cout<<isAnagram(str1,str2)<<endl;
  cout<<reverse_string(str1)<<endl;

  cout<<"Int value of "<<str3<<"is : "<<convert_to_int(str3, len)<<endl;
}
