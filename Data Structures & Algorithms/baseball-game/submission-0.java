class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer>st = new Stack<>();
        int n = operations.length;
        for(int i=0;i<n;i++){
            if(operations[i].equals("C")){
                st.pop();
            }else if(operations[i].equals("D")){
                st.push(2*st.peek());
            }else if(operations[i].equals("+")){
                int first = st.peek();
                st.pop();
                int second = st.peek();
                st.pop();
                st.push(second);
                st.push(first);
                st.push(first+second);

            }else{
                int num = Integer.parseInt(operations[i]);
                st.push(num);
            }
        }
        int ans = 0;
        while(!st.isEmpty()){
            ans+=st.peek();
            st.pop();
        }
        return ans;
        
    }
}