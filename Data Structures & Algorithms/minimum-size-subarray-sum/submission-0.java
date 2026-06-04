class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0 , minlen = Integer.MAX_VALUE , sum = 0;
        for(int right = 0;right<nums.length;right++){
            sum+=nums[right];
            while(left<right && sum>=target){
                sum-=nums[left];
                minlen = Math.min(minlen , right-left+1);

                left++;
            }
            if(sum>=target){
                minlen = Math.min(minlen , right-left+1);
            }
           

        }
        return minlen==Integer.MAX_VALUE?0:minlen;
        
    }
}