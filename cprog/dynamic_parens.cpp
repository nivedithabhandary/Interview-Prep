#include<iostream>
#include<vector>
using namespace std;

void print_valid_parens(int left, int right, string paren, vector<string>& vec) {
  if(right == 0) {
    //vec.push_back(paren);
    cout<<paren<<endl;
  }
  if(left) {
    print_valid_parens(left-1,right,paren + "(",vec);
  }
  if(right > left) {
    print_valid_parens(left,right-1,paren + ")",vec);
  }
}

int main() {
    int n = 3;
    string paren = "";
    vector<string>vec;
    print_valid_parens(n,n,paren,vec);

    vector<string>::iterator it;
    for(it=vec.begin(); it!=vec.end(); it++) {
      cout<<*it<<endl;
    }
}
