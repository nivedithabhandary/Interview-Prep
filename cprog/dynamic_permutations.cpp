#include<iostream>
#include<vector>
#include<string>
using namespace std;

string insertAt(string s, char f, int l) {
  string first = s.substr(0,l);
  string rem = s.substr(l,s.length());
  cout<<first + f + rem<<endl;
  return first + f + rem;
}

vector<string> getPermutations(string x) {
  vector<string> permutations;
  if(x.empty()) {
    return {};
  }
  if(x.length()==0) {
    permutations.push_back("");
    return permutations;
  }
  char first = x[0];
  string rem = x.substr(1, x.length());
  vector<string> words = getPermutations(rem);
  for(int i=0; i<words.size(); i++) {
    for(int j=0; j<=words[i].size(); j++) {
      string s = insertAt(words[i], first, j);
      permutations.push_back(s);
    }
  }
  return permutations;
}

int main() {
  string x = "abc";

  vector<string>res = getPermutations(x);
  for(int i=0; i<res.size(); i++) {
    cout<<res[i]<<endl;
  }
}
