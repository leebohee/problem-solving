/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){ // both nodes are NULL
            return true;
        }
        else if(!p || !q){ // one of node is NULL
            return false;
        }
        
        if(p->val != q->val){ // value of nodes are different
            return false;
        }
        else{
            bool result = isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
            return result;
        }
    }
};
