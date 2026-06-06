
class Solution {

    public int[] pse(int[] heights) {
        int n = heights.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);

        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {

            while (!st.isEmpty() && heights[st.peek()] >= heights[i]) {
                st.pop();
            }

            if (!st.isEmpty()) {
                ans[i] = st.peek();
            }

            st.push(i);
        }

        return ans;
    }

    public int[] nse(int[] heights) {
        int n = heights.length;
        int[] ans = new int[n];
        Arrays.fill(ans, n);

        Stack<Integer> st = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {

            while (!st.isEmpty() && heights[st.peek()] >= heights[i]) {
                st.pop();
            }

            if (!st.isEmpty()) {
                ans[i] = st.peek();
            }

            st.push(i);
        }

        return ans;
    }

    public int largestRectangleArea(int[] heights) {

        int[] ps = pse(heights);
        int[] ns = nse(heights);

        int maxArea = 0;

        for (int i = 0; i < heights.length; i++) {
            int width = ns[i] - ps[i] - 1;
            maxArea = Math.max(maxArea, width * heights[i]);
        }

        return maxArea;
    }
}