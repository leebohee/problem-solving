/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp{
    bool operator()(const ListNode* l1, const ListNode* l2){
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result, *cur, *tmp;
        priority_queue < ListNode*, vector <ListNode*>, cmp > pq; // min heap
        
        for(auto itr = lists.begin(); itr != lists.end(); itr++){
            if(*itr){ // not NULL
                pq.push(*itr);
            }
        }
        
        if(pq.empty()){
            return NULL;
        }
        result = pq.top();
        pq.pop();
        if(result->next){
            pq.push(result->next);
        }
        cur = result;
        
        while(!pq.empty()){
            tmp = pq.top();
            pq.pop();
            cur->next = tmp;
            cur = cur->next;
            if(tmp->next){
                pq.push(tmp->next);
            }
        }
        
        return result;
    }
};
