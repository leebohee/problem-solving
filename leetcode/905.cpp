/***********************************
	A[left]		A[right]
	even		even		=> left++
	even		odd			=> left++, right--
	odd			even		=> swap
	odd			odd			=> right--
/**********************************/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0, right = A.size()-1, tmp;
        
        while(left < right){
            if(A[left] % 2 == 0){
                left++;
                if(A[right] % 2 == 1){
                    right--;
                }
            }
            else{
                if(A[right] % 2 == 0){
                    tmp = A[left];
                    A[left] = A[right];
                    A[right] = tmp;
                }
                else{
                    right--;
                }
            }
        }
        
        return A;
    }
};
