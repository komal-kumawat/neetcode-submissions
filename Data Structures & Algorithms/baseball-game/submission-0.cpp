class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int n = operations.size();
        for(string op:operations){
            if(op=="+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second);
                st.push(first);
                st.push(first+second);

            }else if(op=="C"){
                st.pop();

            }
            else if(op=="D"){
                int top = st.top();
                st.push(2*top);

            }else{
                st.push(stoi(op));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
        
    }
};