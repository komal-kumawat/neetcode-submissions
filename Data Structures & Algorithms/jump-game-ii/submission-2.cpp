class Solution {
public:
    int jump(vector<int>& nums) {
        int currEnd = 0 , farthest = 0 , n = nums.size() , count=0;
        for(int i=0;i<n-1;i++){
            farthest = max(farthest , nums[i]+i);
            if(currEnd == i){
                currEnd = farthest;
                count++;
            }
        }
        return count;
        
    }
};
