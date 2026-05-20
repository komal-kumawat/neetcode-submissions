class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums , vector<int>curr , int index){
        if(index==nums.size()){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[index]);
        helper(nums , curr , index+1);
        curr.pop_back();
        helper(nums , curr , index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums , {} , 0);
        return ans;
        
    }
};
