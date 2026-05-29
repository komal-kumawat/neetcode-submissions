class Solution {
public:
    int sum = 0;
    void backtrack(vector<int>&nums , int index , vector<int>curr){
        if(index==nums.size()){
            int x = 0;
            for(int num:curr){
                x = x^num;
            }
            sum+=x;
            return ;
        }
        curr.push_back(nums[index]);
        backtrack(nums , index+1 , curr);
        curr.pop_back();
        backtrack(nums , index+1 , curr);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>curr;
        backtrack(nums , 0 ,curr);
        return sum;
        
    }
};