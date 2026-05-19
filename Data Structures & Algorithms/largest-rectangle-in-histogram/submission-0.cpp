class Solution {
public:
    vector<int>pse(vector<int>&heights){
        int n = heights.size();
        vector<int>ans(n , -1);
        stack<int>st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);

        }
        return ans;
    }
    vector<int>nse(vector<int>&heights){
        int n = heights.size();
        vector<int>ans(n , n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);

        }
        return ans;


    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>ps = pse(heights);
        vector<int>ns = nse(heights);
        int maxArea = 0;
        for(int i=0;i<ps.size();i++){
            int width = ns[i]-ps[i]-1;
            maxArea = max(maxArea , width*heights[i]);

        }
        return maxArea;
        
    }
};
