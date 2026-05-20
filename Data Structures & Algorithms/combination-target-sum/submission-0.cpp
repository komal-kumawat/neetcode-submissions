class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums , int target , int index , vector<int>curr){
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        if(target<0 || index==nums.size()) return ;
        curr.push_back(nums[index]);
        helper(nums , target-nums[index] , index , curr);
        curr.pop_back();
        helper(nums , target, index+1 , curr);



    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        helper(nums , target , 0 , {});
        return ans;
    }
};
