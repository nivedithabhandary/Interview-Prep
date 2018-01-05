#include<iostream>
#include<string>
using namespace std;
#define SIZE 26

struct Trie {
  bool isEndOfString;
  struct Trie * children[SIZE];
};

struct Trie * getNode() {
  struct Trie *newNode = new Trie();
  for(int i=0; i<SIZE; i++) {
    newNode->children[i] = NULL;
  }
  newNode->isEndOfString = false;
  return newNode;
}

void insert(struct Trie * root, string str) {
  struct Trie *crawler = root;
  for(int i=0; i<str.length(); i++) {
    int index = str[i] - 'a';
    if(!crawler->children[index]) {
      crawler->children[index] = getNode();
    }
    crawler = crawler->children[index];
  }
  crawler->isEndOfString = true;
}

bool search(struct Trie *root, string str) {
  if(!root) {
    return (str.length()==0);
  }
  struct Trie *crawler = root;
  for(int i=0; i<str.length(); i++) {
    int index = str[i] - 'a';
    if(!crawler->children[index]) {
      return false;
    }
    crawler = crawler->children[index];
  }
  return crawler!=NULL && (crawler->isEndOfString);
}

bool search_wildcard(struct Trie *root, string str) {
  struct Trie *crawler = root;
  if(!crawler) {
    return false;
  } else if(crawler->isEndOfString){
    return (str.length()==0);
  } else if(str.length()==0){
      return false;
  }

  if(str[0] == '*') {
    for(int i=0; i<SIZE; i++) {
      return search_wildcard(crawler->children[i],  str.substr(1,str.length()));
    }
  } else {
      return search_wildcard(crawler->children[str[0]-'a'], str.substr(1,str.length()));
  }
  return false;
}

void display(struct Trie *root, char res[], int level) {
  if(root->isEndOfString) {
    res[level] += '\0';
    cout<<res<<"\n";
    return;
  } else {
    for(int i=0; i<SIZE; i++) {
      if(root->children[i]) {
        res[level] += i + 'a';
        display(root->children[i], res, level+1);
      }
    }
  }
}

void count_words(struct Trie *root, int *count) {
  if(root->isEndOfString) {
    *count = *count + 1;
    return;
  } else {
    for(int i=0; i<SIZE; i++) {
      if(root->children[i]) {
        count_words(root->children[i], count);
      }
    }
  }
}


int main() {
    string keys[] = {"the","boat", "going","south","not","north"};
    struct Trie *root = getNode();
    int n = sizeof(keys) / sizeof(keys[0]);
    for(int i=0; i<n; i++) {
        insert(root, keys[i]);
    }
    cout<<"East found : "<<search_wildcard(root, "*or*y")<<endl;
    cout<<"North found : "<<search_wildcard(root, "n**th")<<endl;

    char res[20];
    display(root, res, 0);

    int count = 0;
    count_words(root, &count);
    cout<<"Number of words : "<<count<<endl;
}
