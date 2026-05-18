class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 31;
        while(n>0){
            ans +=pow(2 , i)*(n&1);
            n>>=1;
            i--;
        }
        return ans;
    }
};
