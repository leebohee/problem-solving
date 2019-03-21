struct Node{
	Node** next;
	bool end;
	
	Node(){
		next = new Node* [26] (); // map a~z into 0~25
		end = false;
	}
};

class Trie {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.length();
        Node* cur = root;
        
        for(int i=0; i<len; i++){
        	int idx = word.at(i)-'a';
        	if(!cur->next[idx]){
				cur->next[idx] = new Node;
			}
        	cur = cur->next[idx];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.length();
        Node* cur = root;
        
        for(int i=0; i<len; i++){
        	int idx = word.at(i)-'a';
        	if(!cur->next[idx]){
        		return false;
			}
        	cur = cur->next[idx];
        }
        // check if it is end of word
        return (cur->end ? true : false);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.length();
        Node* cur = root;
        
        for(int i=0; i<len; i++){
        	int idx = prefix.at(i)-'a';
        	if(!cur->next[idx]){
        		return false;
			}
        	cur = cur->next[idx];
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
