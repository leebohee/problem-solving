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
    bool areSymmetricSubTree(TreeNode* left_sub, TreeNode* right_sub){
        if(!left_sub && !right_sub){ // both nodes are NULL
            return true;
        }
        else if(!left_sub || !right_sub){ // one of node is NULL
            return false;
        }
        
        if(left_sub->val != right_sub->val){
            return false;
        }
        bool result1 = areSymmetricSubTree(left_sub->left, right_sub->right);
        bool result2 = areSymmetricSubTree(left_sub->right, right_sub->left);
        return result1 & result2;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return areSymmetricSubTree(root->left, root->right);
    }
};
