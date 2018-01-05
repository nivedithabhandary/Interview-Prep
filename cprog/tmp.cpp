#include <iostream>
#include <string>
using namespace std;

#define SIZE 26

struct Trie {
  struct Trie * children[SIZE];
  bool isEndOfString;
}

struct Trie * getNode() {
  struct Trie *newNode = new Trie();
  for(int i=0; i<SIZE; i++) {
    newNode->children[i] = NULL;
  }
  newNode->isEndOfString = false;
  return newNode;
}

int main() {
  string keys[] = {"the", "land",  "full", "moon", "sun", "happy", "time"};

  struct Trie * root = getNode();

  for(int i=0; i<keys.size(); i++) {
    insert(root, keys[i]);
  }

  search(root, "time");
  search(root, "go");

}
