class Solution {
public:
    bool helper(vector<int>&nums , int index , int target , vector<int>&sides){
        if(index==nums.size()){
            return true;
        }
        for(int i=0;i<4;i++){
            if(sides[i]+nums[index]<=target){
                sides[i]+=nums[index];
                bool check = helper(nums , index+1 , target , sides);
                if(check==true) return true;
                sides[i]-=nums[index];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        for(int num:matchsticks){
            sum+=num;
        }
        if(sum%4!=0){
            return false;
        }
        int total = sum/4;
        vector<int>sides(4 , 0);
        sort(matchsticks.rbegin() , matchsticks.rend());
        return helper(matchsticks , 0 , total , sides);
        
    }
};