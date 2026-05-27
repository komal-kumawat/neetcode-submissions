class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>hash;
        for(int num:nums){
            if(num>0){
                hash.insert(num);
            }
        }
        int i = 1;
        while(hash.count(i)){
            i++;
        }
        return i;
        
    }
};