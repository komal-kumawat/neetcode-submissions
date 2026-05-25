class Solution {
public:

    unordered_map<int,int> mp;
    int preIndex = 0;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int inStart, int inEnd)
    {
        // Base case
        if(inStart > inEnd)
            return NULL;

        // Current root from preorder
        int rootVal = preorder[preIndex++];

        // Create node
        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int index = mp[rootVal];

        // Build left subtree
        root->left = solve(preorder, inorder,
                           inStart, index - 1);

        // Build right subtree
        root->right = solve(preorder, inorder,
                            index + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder indices
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, inorder.size() - 1);
    }
};