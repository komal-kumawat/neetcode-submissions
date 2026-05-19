class Solution {
public:
    unordered_set<int>s;
    int calculate(int n){
        int sum = 0;
        while(n>0){
            sum+=(n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        if(s.count(n)){
            return false;
        }
        s.insert(n);
        n = calculate(n);
        return isHappy(n);
        return false;
    }
};
