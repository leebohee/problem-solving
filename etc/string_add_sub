#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add_string(string num1, string num2){
    int len1 = num1.length(), len2 = num2.length();
    string result = "";
    int idx1 = 1, idx2 = 1, sum, carry = 0;
    while(idx1 <= len1 || idx2 <= len2){
        sum = 0;
        if(idx1 <= len1){
            sum += (num1[len1-idx1]-'0');
            idx1++;
        }
        if(idx2 <= len2){
            sum += (num2[len2-idx2]-'0');
            idx2++;
        }
        cout << sum << endl;
        sum += carry;
        if(sum >= 10){
            carry = 1;
            sum -= 10;
        }
        else{
            carry = 0;
        }
        result += (sum+'0');
         
    }
    if(carry) result += '1';
    reverse(result.begin(), result.end());
    return result;
}

string subtract(string num1, string num2){
    string result = "";
    int len1 = num1.length(), len2 = num2.length();
    int idx1 = 1, idx2 = 1, sub = 0, i;

    while(idx1 <= len1 && idx2 <= len2){
        sub = (num1[len1-idx1]-'0') - (num2[len2-idx2]-'0');
        if(sub < 0){ // borrow carry
            for(i=idx1+1; i<=len1; i++){
                if(num1[len1-i] > '0'){
                    num1[len1-i]--;
                    sub += 10;
                    break;
                }
                else{
                    num1[len1-i] = '9';
                }
            }
        }
        result += (sub+'0');
        idx1++;
        idx2++;
    }
    while(idx1 <= len1){
        result += (num1[len1-idx1]);
        idx1++;
    }
    reverse(result.begin(), result.end());
    
    for(i=0; i<result.length(); i++){
        if(result[i] != '0') break;
    }
    result.erase(0, i); // delete whitespaces
    return result;
}

string sub_string(string num1, string num2){
    string result = "";
    bool bigger = true;
    int len1 = num1.length(), len2 = num2.length();
    // compare num1 and num2
    if(len1 < len2){
        bigger = false;
    }
    else if(len1 == len2){
        for(int i=0; i<len1; i++){
            if(num1[i] < num2[i]){
                bigger = false;
                break;
            }
            if(num1[i] > num2[i]){
                break;
            }
        }
    }
    if(bigger){
        return subtract(num1, num2);
    }
    else{
        result = '-' + subtract(num2, num1);
        return result;
    }
}

int main(){
    cout << "result = ";
    cout << sub_string("1989", "2000") << endl;
    return 0;
}
