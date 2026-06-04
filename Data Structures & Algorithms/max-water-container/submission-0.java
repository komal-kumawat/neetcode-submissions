class Solution {
    public int maxArea(int[] height) {
        int left= 0 , right = height.length-1;
        int maxwater = 0;
        while(left<right){
            int width = right-left;
            int h = Math.min(height[left] , height[right]);
            maxwater = Math.max(maxwater , width*h);
            if(height[left]<=height[right]){
                left++;
            }else{
                right--;
            }

        }
        return maxwater;
        
    }
}
