class Solution {
    public int majorityElement(int[] nums) {
        int count = 0 , ans = -1;
        for(int i=0;i<nums.length;i++){
            if(count==0){
                ans = nums[i];
                count = 1;
            }else if(nums[i]==ans){
                count++;
            }else{
                count--;
            }
        }
        return ans;
        
    }
}