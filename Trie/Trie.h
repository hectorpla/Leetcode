#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <iostream>

class Trie;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        this->children = std::vector<TrieNode*>(26, NULL);
        isWord = false;
    }
    
private:
    std::vector<TrieNode*> children; // (26, NULL);
    bool isWord;
    friend class ::Trie;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(std::string word) {
        TrieNode *cur = root;
        
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(std::string word) {
        TrieNode *cur = root;
        
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->children[index]) {
                cur = cur->children[index];
            }
            else {
                return false;
            }
        }
        return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(std::string prefix) {
        TrieNode *cur = root;
        
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (cur->children[index]) cur = cur->children[index];
            else return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

#endif