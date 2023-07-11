#include <bits/stdc++.h>
using namespace std;

#define CHARSET 256

class TrieNode {
    public:
    bool isWord; // int val;
    TrieNode *children[256];
    TrieNode() {
        this->isWord = false;
        for (int i = 0; i < CHARSET; i++)
        this->children[i] = NULL;
    }
};


class Trie{
    TrieNode *root;
    public:
    Trie() {
       this->root = new TrieNode();
    }

    void Insert(const string &str) {
        TrieNode* crawler = this->root;
        for(int i=0; i<str.size(); i++){
            if(crawler->children[int(str[i])] == NULL){
                crawler->children[int(str[i])] == new TrieNode();
            }
            crawler = crawler->children[int(str[i])];
        }
        crawler->isWord = true;
    }
};

int main() {
    
    return 0;
}