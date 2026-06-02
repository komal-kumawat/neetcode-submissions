class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int product = 1 , countZero = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                countZero++;
            }else{
                product*=nums[i];
            }
            if(countZero>1){
                return new int[n];
            }
        }
        
        if(countZero==1){
            for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i] = product;
            }else{
                nums[i] = 0;
            }
            }
        }
        else{
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[i] = product/nums[i];
            }
        }
        }
        return nums;

        
    }
}  
