# [ 38 ] Count and Say

Created: Apr 13, 2020 8:51 PM
Tags: 3rd week, Leetcode
URL: https://leetcode.com/problems/count-and-say/

### 전체 코드

    class Solution {
    public:
        string next_term(string str){
            int start = 0, end = 0, len = str.length();
            string result;
    
            while(end < len){
                if(str.at(start) == str.at(end)){
                    end++;
                }
                else{
                    result += ((end-start) + '0'); // freq
                    result += str.at(start); // value
                    start = end;
                }
            }
            result += ((end-start) + '0'); // freq
            result += str.at(start); // value
            return result;
        }
        
        string countAndSay(int n) {
            string result = "1";
            for(int i=2; i<=n ;i++){
                result = next_term(result);
            }
            return result;
        }
    };

### 코드 설명

n번째 term은 (n-1)번째 term에서 연속되는 값의 개수 freq과 그 값 value를 이어붙여 만들 수 있다. 예를 들어, n=4일 때의 term "1211"은 

- 1(value)이 1(freq)번 연속됨
- 2(value)가 1(freq)번 연속됨
- 1(value)이 2(freq)번 연속됨

따라서 n=5일 때의 term은 "111221"이 된다.

- 1(value)이 3(freq)번 연속됨
- 2(value)가 2(freq)번 연속됨
- 1(value)가 1(freq)번 연속됨

따라서 n=5일 때의 term은 "312211"이 된다.

이 과정을 구현한 함수가 `next_term()`이다. 이 과정을 n번 반복하면 n번째 term을 구할 수 있다.

(k-1)번째 term의 각 자리수에 대해 (freq, value) 쌍을 이룰 수 있으므로, k번째 term의 최대 가능한 길이는 2^(k-1)이다. 다음 term을 구하기 위해서는 이전 term의 각 자리수를 훑어봐야 하므로, 전체 시간복잡도는 **O(2^0 + 2^1 + ... + 2^(n-1)) = O(2^n)** 이다.
