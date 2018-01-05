#include<iostream>
#include<string>
using namespace std;
#define SIZE 26

struct Trie {
    struct Trie * children[SIZE];
    bool isEndOfString;
};

struct Trie * getNode() {
    struct Trie * newNode = new Trie();
    newNode->isEndOfString = false;
    for(int i=0; i<SIZE; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insert(struct Trie *root, string key) {

    struct Trie *crawler = root;
    for(int i=0; i<key.length(); i++) {
        int index = key[i] - 'a';
        if(!crawler->children[index]) {
            crawler->children[index] = getNode();
        }
        crawler = crawler->children[index];
    }
    crawler->isEndOfString = true;
}

bool search_wildcard(struct Trie *root, string val) {
  struct Trie *crawler = root;

  if (crawler == NULL) {
    return false;
  } else if ((crawler->isEndOfString) && (val.length() == 0)) {
    return true;
  } else if (val.length() == 0) {
    return false;
  }

  if (val[0] == '*') {
    for(int j=0; j<SIZE; j++) {
      bool found = search_wildcard(crawler->children[j], val.substr(1, val.length()));
      if (found) {
        return true;
      }
    }
  } else {
    int index = val[0] - 'a';
    return search_wildcard(crawler->children[index],  val.substr(1, val.length()));
  }
}

bool iterative_wildcard_search(struct Trie *root, string val) {
    struct Trie *crawler = root;
    int index = 0;
    for(int i=0; i<val.length(); i++) {
      if(val[i]=='*') {
        continue;
      } else {
        index = val[i] - 'a';
        if(!crawler->children[index]) {
            return false;
        }
      }
      crawler = crawler->children[index];
    }
    return crawler!=NULL && crawler->isEndOfString;
}

bool search(struct Trie *root, string val) {
    struct Trie *crawler = root;
    for(int i=0; i<val.length(); i++) {
        int index = val[i] - 'a';
        if(!crawler->children[index]) {
            return false;
        }
        crawler = crawler->children[index];
    }
    return crawler!=NULL && crawler->isEndOfString;
}

void display(struct Trie *root, char res[], int level) {
    if(root->isEndOfString) {
        res[level] = '\0';
        cout<<res<<endl;
    } else {
        for(int i=0; i<SIZE; i++) {
            if(root->children[i]) {
                res[level] = i + 'a';
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
    cout<<"East found : "<<iterative_wildcard_search(root, "e*st")<<endl;
    cout<<"North found : "<<iterative_wildcard_search(root, "n*rth")<<endl;
/*
    char res[20];
    display(root, res, 0);

    int count = 0;
    count_words(root, &count);
    cout<<"Number of words : "<<count<<endl;*/
}
