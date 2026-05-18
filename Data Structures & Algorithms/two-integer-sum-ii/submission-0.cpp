class Solution {
public:
    int binary_search(vector<int>&nums , int low , int high , int target){
        
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }

        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0;i<n;i++){
            int check = binary_search(numbers , i+1 , n-1 , target-numbers[i]);
            if(check!=-1){
                return {i+1 , check+1};
            }
        }
        return {-1 , -1};
        
    }
};
