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
    bool is_valid(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == nullptr) return true;

        if(max != nullptr && root->val >= max->val) return false;
        if(min != nullptr && root->val <= min->val) return false;
        return is_valid(root->left, min, root) && is_valid(root->right, root, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return is_valid(root, nullptr, nullptr);
    }
};
