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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result, *cur;
        auto itr = lists.begin();
        int min = INT_MAX, idx = -1;
        
        while(itr != lists.end()){
            if(!(*itr)){
                lists.erase(itr);
                continue;
            }
            if(min > (*itr)->val){
                min = (*itr)->val;
                idx = distance(lists.begin(), itr);
            }
            itr++;
        }
        if(lists.size() == 0){
            return NULL;
        }
        result = lists[idx];
        lists[idx] = lists[idx]->next;
        cur = result;
        if(!lists[idx]){
            lists.erase(lists.begin()+idx);
        }
        
        while(lists.size() > 1){
            min = lists[0]->val;
            idx = 0;
            // find minimum elements among linked lists
            for(int i=1; i<lists.size(); i++){
                if(min > lists[i]->val){
                    min = lists[i]->val;
                    idx = i;
                }
            }
            cur->next = lists[idx];
            lists[idx] = lists[idx]->next;
            cur = cur->next;
            if(!lists[idx]){
                lists.erase(lists.begin()+idx);
            }
        }
        cur->next = lists[0];
        
        return result;
    }
};
