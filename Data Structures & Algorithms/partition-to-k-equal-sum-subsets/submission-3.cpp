class Solution {
public:
    bool helper(vector<int>&nums , int index , vector<int>&arr , int target , int k ){
        if(index== nums.size()){
            for(int num:arr){
                if(num!=target) return false;
            }
            return true;
        }
        for(int i=0;i<k;i++){
            if(arr[i]+nums[index]<=target){
                arr[i]+=nums[index];
                if(helper(nums , index+1 , arr , target , k)) return true;
                arr[i]-=nums[index];
                if(arr[i]==0) break;

            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0 , n= nums.size();
        for(int num:nums){
            sum+=num;
        }
        if(sum%k!=0){
            return false;
        }
        int target = sum/k;
        sort(nums.rbegin() ,  nums.rend());
        vector<int>arr(k , 0);
        return helper(nums , 0 , arr , target , k);
    }
};