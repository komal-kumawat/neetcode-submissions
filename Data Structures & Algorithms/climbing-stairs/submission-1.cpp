class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int first = 1 , second = 2;
        for(int i=3;i<=n;i++){
            int temp = first;
            first = second;
            second = temp+first;
        }
        return second;
        
    }
};
