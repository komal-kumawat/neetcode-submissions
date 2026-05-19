class Solution {
public:
    int reverse(int x) {
        long long MAX = INT_MAX , MIN = INT_MIN;
        bool isnegative = false;
        if(x<0){
            isnegative = true;
            x = x*-1;
        }
        long long res = 0;
        while(x>0){
            long long rem = x%10;
            if(res>MAX/10 || res<MIN/10 || (res==MAX/10 && rem>MAX%10 ) ||(res==MIN/10 && rem<MIN%10)){
                return 0;
            }
            res = res*10+rem;
            x = x/10;
        }
        if(isnegative){
            return -1*res;
        }
        return res;

    }
};
