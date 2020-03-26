# [ 9 ] Palindrome Number

Created: Mar 26, 2020 4:17 PM
Tags: 1st week, Leetcode
URL: https://leetcode.com/problems/palindrome-number/

### 전체 코드

    bool isPalindrome(int x) {
            int origin = x, reverted = 0;
            if(x == 0) return true;
            else if(x < 0 || x%10 == 0){
                return false;
            }
            while(reverted < x){
                reverted = reverted*10 + (x%10);
                x /= 10;
            }
            if(reverted == x || reverted/10 == x){
                return true;
            }
            return false;
        }

### 코드 설명

palindrome은 원래 값과 거꾸로 했을 때의 값이 같은 수를 의미한다. 즉, 절반을 뒤집은 것과 나머지 절반이 같다. 이를 이용하면 모든 자릿수를 뒤집지 않고도 palindrome인지 확인할 수 있다.  다음과 같이 한자리씩 뒤집어 저장한 값 `reverted`가 더 커질 때까지 뒤집는다. 이렇게하면 int 범위 내에서 값이 주어질 때 overflow를 검사하지 않아도 된다.

    while(reverted < x){
    	reverted = reverted*10 + (x%10);
      x /= 10;
    }

주어진 값이 palindrome일 때 전체 자릿수가 홀수라면, `reverted`가 `x`보다 한자리 더 많은 상태에서 반복문을 나올 것이고, 짝수라면 `reverted`와 `x`가 같은 자릿수를 가진 채로 반복문을 나올 것이다.  이를 코드로 나타내면 다음과 같다.

    if(reverted == x || reverted/10 == x){
    	return true;
    }

이때, 주의할 점은 122100와 같이 주어진 값의 끝부분이 0이 연속되면, `x`와 `reverted`가 같은 값을 저장한채로 반복문을 나올 수 있다. 따라서 이 edge case를 반복문을 돌기 전에 예외적으로 처리해주도록 한다.

    if(x == 0) return true;
    else if(x < 0 || x%10 == 0){
    	return false;
    }

주어진 값을 N이라고 하면, N의 전체 자릿수의 절반에 대해 연산을 수행하므로 전체 시간복잡도는 **O(N/2) = O(N)**이다.