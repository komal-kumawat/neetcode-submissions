class Solution {
public:

    bool isSame(TreeNode* p, TreeNode* q) {

        if(!p && !q)
            return true;

        if(!p || !q)
            return false;

        if(p->val != q->val)
            return false;

        return isSame(p->left, q->left) &&
               isSame(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!root)
            return false;

        // check current node
        if(isSame(root, subRoot))
            return true;

        // search left or right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};