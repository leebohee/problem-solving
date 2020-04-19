# [ 160 ] Intersection of Two Linked Lists

Created: Apr 18, 2020 7:17 PM
Tags: 4th week, Leetcode
URL: https://leetcode.com/problems/intersection-of-two-linked-lists/

### 전체 코드

    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    class Solution {
    public:
        ListNode *compare(ListNode *l1, ListNode *l2){
            while(l1){
                if(l1 == l2){
                    return l1;
                }
                else{
                    l1 = l1->next;
                    l2 = l2->next;
                }
            }
            return nullptr;
        }
        
        ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
            ListNode *p1 = l1, *p2 = l2;
            int len1 = 0, len2 = 0;
            // count the number of entries in the linked lists
            while(p1){
                len1++;
                p1 = p1->next;
            }
            while(p2){
                len2++;
                p2 = p2->next;
            }
    				// move the pointer so that the number of entries left becomes the same
            p1 = l1;
            p2 = l2;
            while(len1 > len2){
                p1 = p1->next;
                len1--;
            }
            while(len1 < len2){
                p2 = p2->next;
                len2--;
            }
            return compare(p1, p2);
            
        }
    };

### 코드 설명

cross point 이후에는 두 연결 리스트가 갖는 entry 개수가 같다. 따라서 먼저 두 연결 리스트의 entry를 각각 가리키는 포인터 `p1`, `p2`를 옮겨서 이후에 갖는 entry 개수가 같도록 맞춰준다.

그 후, `compare()` 함수를 통해 연결 리스트의 두 entry가 같은 주소값을 갖는지 확인하면서 cross point를 찾는다.

두 연결 리스트의 길이가 M, N이라 할 때, 시간복잡도는 다음과 같이 계산할 수 있다.

1. 두 연결 리스트의 길이를 구하기 위해서 각각 한번씩 훑는다 ⇒ O(M+N)
2. 포인터를 움직이면서 cross point를 찾는다 ⇒ O(max(M, N))

따라서, 전체 시간복잡도는 O(M+N+max(M, N)) = **O(max(M, N))**이다.