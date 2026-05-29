class Solution {
public:
    int dfs(vector<int>&nums , int index , int total){
        if(index==nums.size()){
            return total;
        }
        return dfs(nums , index+1 , total^nums[index])+
            dfs(nums , index+1 , total);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int res = dfs(nums , 0 , 0);
        return res;
        
    }
};