#define NUM 26

struct Node{
    bool null;
    Node* children[NUM];
    Node(): null(false) {
        for(int i=0; i<NUM; i++) children[i] = nullptr;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        int len = word.length();
        for(int i=0; i<len; i++){
            if(cur->children[word[i]-'a'] == nullptr) cur->children[word[i]-'a'] = new Node();
            cur = cur->children[word[i]-'a'];
        }
        cur->null = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        int len = word.length();
        for(int i=0; i<len; i++){
            if(cur->children[word[i]-'a'] == nullptr) return false;
            cur = cur->children[word[i]-'a'];
        }
        if(cur->null) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        int len = prefix.length();
        for(int i=0; i<len; i++){
            if(cur->children[prefix[i]-'a'] == nullptr) return false;
            cur = cur->children[prefix[i]-'a'];
        }
        return true;
    }
private:
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */