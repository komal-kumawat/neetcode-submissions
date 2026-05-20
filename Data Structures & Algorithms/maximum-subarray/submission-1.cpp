class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        for(int num:nums){
            sum = max(sum+num , num);
            maxsum = max(maxsum , sum);
        }
        return maxsum;

    }
};
