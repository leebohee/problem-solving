# [ 7 ] Reverse Integer

Created: Mar 26, 2020 3:43 PM
Property 1: https://leetcode.com/problems/reverse-integer/

### 전체 코드

    int reverse(int x){
    	int reversed = 0;
    	bool positive = true;
    
    	if(x < 0){
    		positive = false;
    	}
    
    	while(x != 0){
    		// check overflow
    		if(positive){
    			if(reversed > INT_MAX/10){
    				return 0;
    			}
    			/*
    			if(reversed == INT_MAX/10 && x%10 > 7){
    				return 0;
    			}
    			*/	
    		}
    		else{
    			if(reversed < INT_MIN/10){
    				return 0;
    			}
    			/*
    			if(reversed == INT_MIN/10 && x%10 < -8){
    				return 0;
    			}
    			*/
    		}
    
    		reversed = reversed*10 + x%10;
    		x /= 10;
    	}
    	return reversed;
    }

### 나눗셈/나머지 연산

C, C++, Java는 나눗셈에 대하여 기본적으로 **버림(truncate)**을 한다. 반면 Python은 나눗셈에 대하여 **내림(floor)**을 한다. 따라서 `-13 나누기 10 = -1.3`를 할 때 다음과 같은 다른 결과를 갖게 된다.

- C, C++, Java: 몫 = -1, 나머지 = -3
- Python: 몫 = -2, 나머지 = 7

### 코드 설명

C++의 경우, 음수를 10으로 나눈 나머지는 양수와 마찬가지로 1의 자리 숫자에 음의 부호를 붙인 값이다. 다시 말하자면, `-13 % 10`의 결과값은 `-3`이다. 이러한 성질을 이용하면 양수와 음수를 구분할 필요없이 동일한 연산을 해 입력받은 수를 뒤집을 수 있다. 수를 뒤집는 것은 1의 자리 숫자를 가장 높은 자릿수로 하면 되는데 다음과 같이 하면 된다. 

    while(x != 0){
    		reversed = reversed*10 + x%10;
    		x /= 10;
    	}

한편, 자릿수를 뒤집을 때마다 overflow를 검사해야하는데, INT_MAX = 2,147,483,647이고 INT_MIN = -2,147,483,648이므로 다음과 같이 주어진 값이 음수일 때와 양수일 때 구분해서 검사해야 한다.

    if(positive){
    			if(reversed > INT_MAX/10){ // case 1
    				return 0;
    			}
    			if(reversed == INT_MAX/10 && x%10 > 7){ // case 2
    				return 0;
    			}
    		}
    		else{
    			if(reversed < INT_MIN/10){ // case 3
    				return 0;
    			}
    			if(reversed == INT_MIN/10 && x%10 < -8){ // case 4
    				return 0;
    			}
    		}

이때 입력으로 주어지는 값 자체가 int 범위 내에서 주어지기 때문에 case 2와 case 4에 대해서는 발생할 일이 없으므로 최종 코드에서는 없어도 된다.