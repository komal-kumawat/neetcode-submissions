class Solution {
public:
    bool check(vector<int>& nums , int k , int capacity){
        int sum = 0 , n = nums.size() , part = 1;
        for(int i=0;i<n;i++){
            if(sum+nums[i]>capacity){
                part++;
                sum = 0;
            }
            sum+=nums[i];
            if(part>k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin() , nums.end()) ;
        int high = accumulate(nums.begin() , nums.end() , 0);
        int ans= 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            bool x = check(nums , k , mid);
            if(x){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }

        }
        return ans;
        
    }
};