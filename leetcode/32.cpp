class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(),result = 0;
        stack <int> st;
        
        st.push(-1);
        for(int i=0; i<len; i++){
            if(s.at(i) == '('){ // '(' => push index
                st.push(i);
            }    
            else{  // ')' => pop
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{ 
                    result = max(result, i-st.top());
                }
            }
        }
        return result;
    }
};
