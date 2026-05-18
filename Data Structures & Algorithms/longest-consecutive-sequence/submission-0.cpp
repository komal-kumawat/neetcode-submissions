class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>seen;
        for(int num:nums){
            seen.insert(num);
        }
        int maxcount = 0;
        for(int num:nums){
            
            if(!seen.count(num-1)){
                int n = num;
                while(seen.count(n)){
                    n+=1;
                }
                maxcount = max(maxcount , n-num);

                
            }
        }
        return maxcount;
    }
};
