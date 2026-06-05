
class Solution {
    public int[] asteroidCollision(int[] asteroids) {

        Stack<Integer> st = new Stack<>();

        for (int asteroid : asteroids) {

            boolean destroyed = false;

            while (!st.isEmpty() &&
                   st.peek() > 0 &&
                   asteroid < 0) {

                // Current asteroid is larger
                if (Math.abs(asteroid) > st.peek()) {
                    st.pop();
                }

                // Both are equal
                else if (Math.abs(asteroid) == st.peek()) {
                    st.pop();
                    destroyed = true;
                    break;
                }

                // Stack asteroid is larger
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroid);
            }
        }

        int[] ans = new int[st.size()];

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.pop();
        }

        return ans;
    }
}