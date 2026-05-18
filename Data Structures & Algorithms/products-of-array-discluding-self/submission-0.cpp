class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1 , countZeroes = 0;
        vector<int>ans(nums.size() , 0);
        for(int num:nums){
            if(num==0){
                countZeroes++;
            }else{
                product*=num;
            }
            if(countZeroes>1){
                return ans;
            }
        }
        if(countZeroes==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    ans[i] = product;
                    return ans;
                }
            }

        }else{
            for(int i=0;i<nums.size();i++){
                ans[i] = product/nums[i];
            }

        }
        return ans;
    }
};
