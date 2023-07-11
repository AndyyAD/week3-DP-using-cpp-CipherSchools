// C++ implementation of delete
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 256

class TrieNode
{
  public:
    bool IsWord;
    TrieNode *Children[ALPHABET_SIZE];
    TrieNode()
    {
        this->IsWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            this->Children[i] = NULL;
        }
    }
};

class Trie
{
    TrieNode *root;

  public:
    Trie()
    {
        root = new TrieNode();
    }

    void Insert(string str)
    {
        TrieNode *crawler = this->root;
        for (int i = 0; i < str.size(); i++)
        {
            if (!crawler->Children[int(str[i])])
            {
                crawler->Children[int(str[i])] = new TrieNode();
            }
            crawler = crawler->Children[int(str[i])];
        }
        crawler->IsWord = true;
    }

    bool Search(string str)
    {
        TrieNode *crawler = this->root;
        for (int i = 0; i < str.size(); i++)
        {
            if (!crawler->Children[int(str[i])])
            {
                return false;
            }
            crawler = crawler->Children[int(str[i])];
        }
        return (crawler->IsWord == true);
    }

    bool IsLeaf(TrieNode *crawler)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (crawler->Children[i])
                return false;
        }
        return true;
    }

    bool RemoveUtil(TrieNode *crawler, string &str, int curr, int len)
    {
        if (crawler)
        {
            if (curr == len)
            {
                crawler->IsWord = false;
                if (this->IsLeaf(crawler))
                    return true;
                return false;
            }
            else
            {
                if (RemoveUtil(crawler->Children[int(str[curr])], str, curr + 1, len))
                {
                    delete (crawler->Children[int(str[curr])]);
                    return (this->IsLeaf(crawler) && !crawler->IsWord);
                }
            }
        }
        return false;
    }

    void Remove(string str)
    {
        TrieNode *crawler = this->root;
        this->RemoveUtil(crawler, str, 0, str.size());
    }

    void PrintDictionaryHelper(TrieNode *crawler, string & str)
    {
        if (crawler)
        {
            if (crawler->IsWord)
            {
                cout << str << "\n";
            }

            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                if (crawler->Children[i])
                {
                    str += char(i);
                    PrintDictionaryHelper(crawler->Children[i], str);
                    str = str.substr(0, str.size() - 1);
                }
            }
        }
    }

    void PrintDictionary()
    {
        TrieNode *crawler = this->root;
        string str = "";
        PrintDictionaryHelper(crawler, str);
    }
};

int main()
{
    Trie trie;
    trie.Insert("DOG");
    trie.Insert("CAT");
    trie.Insert("DO");
    trie.PrintDictionary();
    trie.Remove("DOG");
    trie.PrintDictionary();
}


// disjoint 
#include <bits/stdc++.h>
using namespace std;

// Naive Implementation
class DisjointSet
{
    int *parent;
    int N;

public:
    DisjointSet(int N)
    {
        this->N = N;
        this->parent = new int[this->N];
        for (int i = 0; i < N; i++)
            this->parent[i] = i;
    }

    //returns true,if A and B are connected, else it will return false.
    bool Find(int A, int B)
    {
        return (this->parent[A] == this->parent[B]);
    }

    void Union(int A, int B)
    {
        int temp = this->parent[A];
        for (int i = 0; i < this->N; i++)
        {
            if (this->parent[i] == temp)
                this->parent[i] = this->parent[B];
        }
    }
};

class OptimizedDisjointSet
{
    int *parent, *_size;
    int N;

public:
    OptimizedDisjointSet(int N)
    {
        this->N = N;
        parent = new int[this->N + 1];
        _size = new int[this->N + 1];
        for (int i = 1; i <= N; i++)
        {
            parent[i] = i;
            _size[i] = 1;
        }
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (_size[a] > _size[b])
            swap(a, b);

        if (a != b)
        {
            parent[a] = b;
            _size[b] += _size[a];
        }
    }

    int Find(int a)
    {
        if (a != parent[a])
            parent[a] = Find(parent[a]);
        return parent[a];
    }
};