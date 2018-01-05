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
    cout<<"East found : "<<search(root, "east")<<endl;
    cout<<"North found : "<<search(root, "north")<<endl;

    char res[20];
    display(root, res, 0);

    int count = 0;
    count_words(root, &count);
    cout<<"Number of words : "<<count<<endl;
}
