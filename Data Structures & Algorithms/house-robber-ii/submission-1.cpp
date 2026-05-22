class Solution {
public:
    int helper(vector<int>&nums , int start , int end){
        int n = end-start+1;
        
        int prev2 = nums[start];
        int prev1= max(nums[start] , nums[start+1]);
        for(int i =2;i<n;i++){
            int curr = max(prev1 , prev2+nums[start+i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0] , nums[1]);
        int case1 = helper(nums , 0 ,n-2);
        int case2 = helper(nums , 1 , n-1);
        return max(case1 , case2);
        
    }
};
