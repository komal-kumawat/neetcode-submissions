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
    int helper(TreeNode* root){
        if(!root) return 0;
        int left = root->left? helper(root->left):0;
        int right = root->right? helper(root->right):0;
        if(left<0 || right<0 || abs(left-right)>1) return -1;
        return 1+max(left , right);

    }
     
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int ans = helper(root);
        return ans==-1?false:true;
        
    }
};
