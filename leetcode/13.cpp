class Solution {
private:
    unordered_map <char, int> symbol_map;
public:
    Solution(){
        // store matching information of symbol with value
        symbol_map.insert(make_pair('I', 1));
        symbol_map.insert(make_pair('V', 5));
        symbol_map.insert(make_pair('X', 10));
        symbol_map.insert(make_pair('L', 50));
        symbol_map.insert(make_pair('C', 100));
        symbol_map.insert(make_pair('D', 500));
        symbol_map.insert(make_pair('M', 1000));
    }
    int romanToInt(string s) {
        int prev = 0, cur = 1, len = s.length(), val;
        
        val = symbol_map[s.at(0)];
        while(cur < len){
            if(symbol_map[s.at(prev)] >= symbol_map[s.at(cur)]){
                val += symbol_map[s.at(cur)];
            }
            else{
                val = val - 2*symbol_map[s.at(prev)] + symbol_map[s.at(cur)];
            }
            cur++;
            prev++;
        }
        
        return val;
    }
};
