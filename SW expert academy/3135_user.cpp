struct node{
	int ref;
	struct node* next[27];
} Node[1100000];
int idx;

struct node* dir;

struct node* my_malloc(){
	Node[idx].ref = 0;
	for(int i = 0; i < 27; i++){
		Node[idx].next[i] = nullptr;
	}
	return &(Node[idx++]);
}

void init(void) {
	idx = 0;
	dir = my_malloc();
}

void insert(int buffer_size, char *buf) {
	struct node* cur = dir;
	for(int i = 0; i < buffer_size; i++){
		if(cur->next[buf[i]-'a'] == nullptr){
			cur->next[buf[i]-'a'] = my_malloc();
		}
		cur = cur->next[buf[i]-'a'];
		(cur->ref)++;
	}
	cur->next[26] = my_malloc(); // null character
}

int query(int buffer_size, char *buf) {
	int cnt = 0;
	struct node* cur = dir;
	
	for(int i = 0; i < buffer_size; i++){
		if(cur->next[buf[i]-'a'] == nullptr){
			return 0;
		}
		cur = cur->next[buf[i]-'a'];
	}
	return cur->ref;
}
