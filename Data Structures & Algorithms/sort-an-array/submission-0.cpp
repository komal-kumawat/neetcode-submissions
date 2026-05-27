class Solution {
public:
    vector<int>merge(vector<int>arr1 , vector<int>arr2){
        vector<int>ans;
        int m = arr1.size() , n = arr2.size();
        int i=0 , j = 0;
        while(i<m && j<n){
            if(arr1[i]<=arr2[j]){
                ans.push_back(arr1[i++]);
            }else{
                ans.push_back(arr2[j++]);
            }
        }
        while(i<m){
            ans.push_back(arr1[i++]);
        }
        while(j<n){
            ans.push_back(arr2[j++]);
        }
        return ans;
    }
    vector<int>mergesort(vector<int>nums , int low , int high){
        if(low==high){
            return {nums[low]};
        }
        int mid = low+(high-low)/2;
        vector<int>left = mergesort(nums , low , mid);
        vector<int>right = mergesort(nums , mid+1 , high);
        return merge(left , right);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return nums;
        return mergesort(nums , 0 , n-1);
        
    }
};