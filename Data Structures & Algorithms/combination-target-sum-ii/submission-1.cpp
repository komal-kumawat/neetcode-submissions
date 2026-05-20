class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums , int target , int index , vector<int>curr){
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        if(target<0 || index==nums.size()) return ;
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1] ) continue;
            curr.push_back(nums[i]);
            helper(nums , target-nums[i] , i+1 , curr);
            curr.pop_back();
        }
        



    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        helper(nums , target , 0 , {});
        return ans;
    }
};
