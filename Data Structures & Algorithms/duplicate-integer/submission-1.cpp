class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>hash;
        for(auto num:nums){
            hash[num]++;
            if(hash[num]==2){return true;}
        }
        return false;
    }
};