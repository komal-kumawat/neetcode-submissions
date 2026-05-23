class Solution {
public:
    int jump(vector<int>& nums) {
        int currentEnd = 0 , n = nums.size() , farthest = 0 , count = 0;
        for(int i=0;i<n-1;i++){
            farthest = max(farthest , nums[i]+i);
            if(i==currentEnd){
                count++;
                currentEnd= farthest;
            }

        }
        return count;
        
    }
};
