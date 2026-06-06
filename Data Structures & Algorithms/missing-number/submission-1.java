class Solution {
    public int missingNumber(int[] nums) {
        int x1 = 0 , x2 = 0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            x1 = x1^i;
            x2 = x2^nums[i];
        }
        return x1^x2^n;
        
    }
}
