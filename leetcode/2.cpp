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
        
        while(true){
            if(l1 != NULL && l2!=NULL){
                cur->val = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 == NULL && l2!=NULL){
                cur->val = l2->val;
                l2 = l2->next;
            }
            else if(l1 != NULL && l2 == NULL){
                cur->val = l1->val;
                l1 = l1->next;
            }
            else{
                if(carry) cur->val = 1;
                else if(prev != NULL){
                    prev->next = NULL;
                    delete cur;
                }
                return result;
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
        }
};
