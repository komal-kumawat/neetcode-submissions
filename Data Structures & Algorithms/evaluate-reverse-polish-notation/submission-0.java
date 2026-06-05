class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < tokens.length; i++) {
            if (tokens[i].equals("+")) {
                int first = st.pop();
                int second = st.pop();
                st.push(first + second);
            } else if (tokens[i].equals("-")) {
                int first = st.pop();
                int second = st.pop();
                st.push(second-first);
            } else if (tokens[i].equals("*")) {
                int first = st.pop();
                int second = st.pop();
                st.push(second*first);
            } else if (tokens[i].equals("/")) {
                int first = st.pop();
                int second = st.pop();
                st.push(second/first);
            } else {
                st.push(Integer.parseInt(tokens[i]));
            }
        }
        return st.peek();
    }
}
