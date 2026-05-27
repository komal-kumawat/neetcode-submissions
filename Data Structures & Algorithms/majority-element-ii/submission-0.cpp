class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() , count1 = 0 , count2 = 0 , num1= INT_MIN , num2 = INT_MIN;
        for(int num:nums){
            if(count1==0 && count2==0){
                num1 = num;
                count1 = 1;
            }else if(count2==0 && num!=num1){
                num2 = num;
                count2 = 1;
            }
            else if(num==num1){
                count1++;
            }
            else if(num==num2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int num:nums){
            if(num==num1){
                count1++;
            }
            if(num==num2){
                count2++;
            }
        }
        if(count1>n/3 && count2 >n/3){
            return {num1 , num2};
        }
        if(count1>n/3){
            return {num1};
        }
        if(count2>n/3){
            return {num2};
        }
        return {};


        
    }
};