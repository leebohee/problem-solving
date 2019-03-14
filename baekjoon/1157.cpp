#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

char FreqAlphabet(string word){
	int freq[26] = {0};
	int len = word.length();
	
	for(int i=0; i<len; i++){
		// compare by ascii value
		if(word.at(i) <= 90){ // upper case
			freq[word.at(i)-65]++;
		}
		else{ // lower case
			freq[word.at(i)-97]++;
		}
	}
	
	int idx=0, max=freq[0];
	bool several = false;
	
	for(int i=1; i<26; i++){
		if(max < freq[i]){
			max = freq[i];
			idx = i;
			several = false;
		}
		else if(max == freq[i]){
			several = true;
		}
	}
	
	if(several){
		return '?';
	}
	return idx+65;
}

int main(){
	string word;
	
	getline(cin, word);
	cout << FreqAlphabet(word);
	
	return 0;
}
