// time complexity = O(K^2)
bool is_valid_wordsquare(vector<string>& words, int K){
	for(int i=0; i<K; i++){ // i-th word
		for(int j=0; j<K; j++){ // j-th word
			if(words[i].at(j) != words[j].at(i)) return false;
		}
	}
	return true;
}

vector< vector<string> > result;
// N words
// time complexity = O(nCr(N, K)*K!*K^2)
void find_all_wordsquares(vector<string>& words_set, int K, vector<string>& words){
	if(words.size() == K){
		if(is_valid_wordsquare(words, K)) result.push_back(words);
	}
	else{
		for(int i=0; i<words_set.size(); i++){
			if(!contain(words_set[i], words)){
				words.push_back(words_set[i]);
				find_all_wordsquares(words_set, K, words);
				words.pop_back();
			}
		}
	}
}

#define CHILD_NUM 26
struct Node{
	bool is_null;
	Node* children[CHILD_NUM] = {nullptr, };
	vector<string> startBy; // all strings with the same prefix
};

Node* root; // root of trie
void add(string str){
	cout << "add() called\n";
	Node* cur = root;
	for(int i=0; i<str.length(); i++){
		char ch = str[i];
		cout << cur << endl;
		if(cur->children[ch-'a'] == nullptr){
			cout << "create node " << ch << endl;
			cur->children[ch-'a'] = new Node;
			cur->children[ch-'a']->is_null = false;
		}
		cur = cur->children[ch-'a'];
	}
	cur->is_null = true;
}

bool is_exist(string str){
	cout << "is_exist() called\n";
	Node* cur = root;
	for(int i=0; i<str.length(); i++){
		char ch = str[i];
		if(cur->children[ch-'a'] == nullptr){
			return false;
		}
		cur = cur->children[ch-'a'];
	}
	if(cur->is_null) return true;
	else return false;
}

string get_prefix(vector<string>& words, int len){
	string prefix = "";
	for(int i=0; i<len; i++){
		prefix += words[i].at(len);
	}
}

vector<string> find_by_prefix(vector<string>& words_set, string prefix){
	Node* cur = root;
	for(int i=0; i<prefix.length(); i++){
		char ch = prefix[i];
		if(cur->children[ch-'0'] == nullptr) return {};
		cur = cur->children[ch-'0'];
	}
	return cur->startBy;
}

vector<string> build_wordsqure(vector<string>& words_set, vector<string>& words, int K){
	if(words.size() == K){
		if(is_valid_wordsquare(words, K)) result.push_back(words);
	}
	else{
		string prefix = get_prefix(words, words.size());
		for(string& word: find_by_prefix(words_set, prefix)){
			words.push_back(word);
			build_wordsqure(words_set, words, K);
			words.pop_back();
		}
	}
}

void find_all_wordsquares(vector<string>& words_set, int K, vector<string>& words){
	for(int i=0; i<words_set.size(); i++){
		build_wordsqure(words_set, K, {words_set[i]});
	}
}
