#define SIZE 26

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.length();
        int* last_idx = new int [SIZE];
        memset(last_idx, -1, sizeof(int)*SIZE);
        
        // store each characters' index of last appearance
        for(int i=0; i<len; i++){
            last_idx[S.at(i) - 'a'] = i;
        }
        
        vector <int> result;
        int start = 0, end = 0;
        for(int i=0; i<len; i++){
            end = max(end, last_idx[S.at(i)-'a']);
            if(end == i){
                result.push_back(end-start+1);
                start = i + 1;
            }
        }

        return result;
    }
};
