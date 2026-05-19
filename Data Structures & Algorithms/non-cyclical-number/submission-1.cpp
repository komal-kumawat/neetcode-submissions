class Solution {
public:
    
    int calculate(int n){
        int sum = 0;
        while(n>0){
            sum+=(n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1 && !s.count(n)){
            s.insert(n);
            n = calculate(n);
        }
        return n==1;
    }
};
