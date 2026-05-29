class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(int n , int index , int k , vector<int>curr){
        if(curr.size()>k) return ;
        if(index>n){
            if(curr.size()==k){
                ans.push_back(curr);
            }
            return ;
        }
        curr.push_back(index);
        backtrack(n , index+1 , k , curr);
        curr.pop_back();
        backtrack(n ,index+1 , k , curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        backtrack(n , 1 , k , curr);
        return ans;
        
    }
};