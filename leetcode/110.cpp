/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        
        int left_h = height(root->left);
        if(left_h < 0) return -1;
        int right_h = height(root->right);
        if(right_h < 0) return -1;
        
        if(abs(left_h - right_h) > 1) return -1;
        else return max(left_h, right_h) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};
