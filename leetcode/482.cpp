class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int len = S.length(), idx = 0;
        char* new_str = new char [len+1];
        
        for(int i=0; i<len; i++){
            if(S.at(i) == '-'){
                // skip
            }
            else if(S.at(i) >= 'a' && S.at(i) <= 'z'){ // lower case
                new_str[idx] = S.at(i) - 'a' + 'A'; // convert to upper case
                idx++;
            }
            else{ // number or upper case
                new_str[idx] = S.at(i);
                idx++;
            }
        }
        new_str[idx] = '\0';
        int q = strlen(new_str) / K;
        int r = strlen(new_str) % K;
        idx = 0;
        string license_key;
        for(int i=0; i<r; i++, idx++){
            license_key += new_str[idx];
        }
        if((r != 0) && (q != 0)) license_key += '-';
        cout  << q;
        for(int i=0; i<q; i++){
            for(int j=0; j<K; j++, idx++){
                license_key += new_str[idx];
            }
            if(i != q-1) license_key += '-';
        }
        return license_key;
    }
};
