class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0 , n= digits.size();
        for(int i=n-1;i>=0;i--){
            int sum = carry;
            sum+=digits[i];
            if(i==n-1){
                sum++;
            }
            digits[i] = sum%10;
            carry = sum/10;
        }
        if(carry>0){
            digits.insert(digits.begin() , carry);
        }
        return digits;
    }
};
