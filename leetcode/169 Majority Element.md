# [ 169 ] Majority Element

Created: Apr 16, 2020 10:20 PM
Tags: 4th week, Leetcode
URL: https://leetcode.com/problems/majority-element/

### 전체 코드

    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int, int> umap;
            int n = nums.size(), half = n / 2;
            
            for(int& v: nums){
                auto itr = umap.find(v);
                if(itr == umap.end()){
                    umap.insert(make_pair(v, 1));
                }
                else{
                    itr->second++;
                    if(itr->second > half){
                        return v;
                    }
                }
            }
            return nums[0];
        }
    };

### 코드 설명

Hash map에 key를 원소 값, value를 원소의 빈도로 하여 배열을 순회하며 업데이트 해나간다. 이때 원소의 빈도가 전체 배열의 길이의 절반보다 커지면 원소 값을 반환한다. 배열의 크기가 1일 때에는 첫번째 원소 값을 그대로 반환한다.

주어진 배열의 길이가 N일 때, 전체 시간복잡도는 **O(N)**이다.