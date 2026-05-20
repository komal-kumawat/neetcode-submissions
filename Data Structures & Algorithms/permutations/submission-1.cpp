class Solution {
public:
    vector<vector<int>>ans;
    
    void helper(vector<int>&nums , vector<int>curr , vector<bool>&used){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            helper(nums , curr , used);
            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool>used(n , false);
        helper(nums , {} , used);
        return ans;
    }
};
