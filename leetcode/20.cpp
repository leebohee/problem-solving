class Solution {
public:
    bool isValid(string str) {
        stack <char> s;
        int len = str.length();
        char ch;
        
        for(int i=0; i<len; i++){
            if(str.at(i) == '(' || str.at(i) == '{' || str.at(i) == '['){
                s.push(str.at(i));
            }
            else{
                if(s.size() == 0){ // more closed parenthese
                    return false;
                }
                
                ch = s.top();
                s.pop();
                if(str.at(i) == ')' && ch != '('){
                    return false;
                }
                if(str.at(i) == '}' && ch != '{'){
                    return false;
                }if(str.at(i) == ']' && ch != '['){
                    return false;
                }
            }
        }
        
        if(s.size() != 0){ // more open parentheses
            return false;
        }
        else{
            return true;
        }
    }
};
