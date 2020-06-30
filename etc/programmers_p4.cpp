#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int len = number.length() - k;
    string answer = number.substr(k);
    for(int i=k-1; i>=0; i--){
        int j=0;
        while(j < len){
            if(number[i] >= answer[j]){
                char tmp = number[i];
                number[i] = answer[j];
                answer[j] = tmp;
                j++;
            }
            else break;
        }
    }
    return answer;
}
