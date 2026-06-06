class StockSpanner {
    ArrayList<Integer>arr = new ArrayList<>();
    Stack<Integer>st;
    public StockSpanner() {
        st = new Stack<>();
        
    }
    
    public int next(int price) {
        arr.add(price);
        while(!st.isEmpty() && arr.get(st.peek())<=arr.get(arr.size()-1)){
            st.pop();
        }
        int ans = 1;
        if(!st.isEmpty()){
        ans = arr.size()-st.peek()-1;
        }else{
            ans = arr.size();
        }
        st.push(arr.size()-1);
        return ans;
        
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */