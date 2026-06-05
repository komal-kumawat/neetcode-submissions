class MinStack {
    Stack<Integer> st = new Stack<>();
    Stack<Integer> minSt = new Stack<>();

    public MinStack() {}

    public void push(int val) {
        st.push(val);
        if (minSt.isEmpty() || val <= minSt.peek())
            minSt.push(val);
    }

    public void pop() {
        int num = st.pop();
        if (num == minSt.peek()) {
            minSt.pop();
        }
    }

    public int top() {
        return st.peek();
    }

    public int getMin() {
        return minSt.isEmpty() ? -1 : minSt.peek();
    }
}
