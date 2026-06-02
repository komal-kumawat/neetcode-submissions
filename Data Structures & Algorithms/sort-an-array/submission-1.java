class Solution {
    private int[] merge(int[] nums1 , int[] nums2){
        int[] ans  = new int[nums1.length + nums2.length];
        int i=0 , j= 0 , k=0 , m = nums1.length , n = nums2.length;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                ans[k++] = nums1[i++];
            }else{
                ans[k++] = nums2[j++];
            }
        }
        while(i<m){
            ans[k++] = nums1[i++];
        }
        while(j<n){
            ans[k++] = nums2[j++];
        }
        return ans;
    }
    private int[] mergeSort(int[] nums , int low , int high){
        if (low == high) {
            return new int[]{nums[low]};
        }
        int mid = low+(high-low)/2;
        int[] left = mergeSort(nums , low , mid);
        int[] right = mergeSort(nums , mid+1 , high);
        return merge(left , right);
    }
    public int[] sortArray(int[] nums) {
        return mergeSort(nums , 0 , nums.length-1);
        
    }
}