class Solution {
private:
    vector <string> valid_exp;
    
public:
    void generateValidSubExp(int n, int open, int closed, string subexp){
        if(open < n){
            generateValidSubExp(n, open+1, closed, subexp+"(");
        }
        if(closed < open){
            generateValidSubExp(n, open, closed+1, subexp+")");
        }
        if(open == n && closed == n){
            valid_exp.push_back(subexp);
        }
    }
    vector<string> generateParenthesis(int n) {
        generateValidSubExp(n, 1, 0, "(");
        return valid_exp;
    }
};
