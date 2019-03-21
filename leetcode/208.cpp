struct Node{
    char val;
    vector <Node*> next;
    
    Node(char _val){
        val = _val;
    }
};

class Trie {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('-');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        int len = word.length(), size;
        bool find;
        
        for(int i=0; i<len; i++){
            size = (cur->next).size();
            find = false;
            for(int j=0; j<size; j++){
                if(!cur->next[j]){
                    continue;
                }
                if(word.at(i) == cur->next[j]->val){
                    cur = cur->next[j];
                    find = true;
                    break;
                }
            }
            if(!find){
                (cur->next).push_back(new Node(word.at(i)));
                cur = cur->next[size];
            }
        }
        cur->next.push_back(NULL);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = this->root;
        int len = word.length(), size;
        bool find;
        
        for(int i=0; i<len; i++){
            size = cur->next.size();
            find = false;
            for(int j=0; j<size; j++){
                if(!cur->next[j]){
                    continue;
                }
                if(word.at(i) == cur->next[j]->val){
                    cur = cur->next[j];
                    find = true;
                    break;
                }
            }
            if(!find){
                return false;
            }
        }
        
        // find NULL 
        size = cur->next.size();
        for(int j=0; j<size; j++){
            if(!cur->next[j]){
                return true;
            }
        }
        return false;      
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = this->root;
        int len = prefix.length(), size;
        bool find;
        
        for(int i=0; i<len; i++){
            size = cur->next.size();
            find = false;
            for(int j=0; j<size; j++){
                if(!cur->next[j]){
                    continue;
                }
                if(prefix.at(i) == cur->next[j]->val){
                    cur = cur->next[j];
                    find = true;
                    break;
                }
            }
            if(!find){
                return false;
            }
        }
        return true; 
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
