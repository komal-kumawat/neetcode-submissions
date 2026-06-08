class Solution {
    public int kthSmallest(TreeNode root, int k) {

        Stack<TreeNode> st = new Stack<>();
        TreeNode curr = root;

        while (curr != null || !st.isEmpty()) {

            while (curr != null) {
                st.push(curr);
                curr = curr.left;
            }

            curr = st.pop();
            k--;

            if (k == 0)
                return curr.val;

            curr = curr.right;
        }

        return -1;
    }
}