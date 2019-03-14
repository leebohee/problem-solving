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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result, *cur, *prev;
        bool carry = false;
        int i=0;
        result = new ListNode(0);
        cur = result;
        
        while(l1 || l2){
            if(l1){
                cur->val += l1->val;
                l1 = l1->next;
            }
            if(l2){
                cur->val += l2->val;
                l2 = l2->next;
            }
            
            if(carry){
                cur->val++;
                carry = false;
            }
            if(cur->val >= 10){
                carry = true;
                cur->val -= 10;
            }
            cur->next = new ListNode(0);
            prev = cur;
            cur = cur->next;
        }
        
        if(carry) cur->val = 1;
        else if(prev != NULL){
            prev->next = NULL;
            delete cur;
        }
        return result;
    }
};
