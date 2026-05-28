class Solution {
public:
    int mySqrt(int x) {
        long long low = 0 , high = x;
        while(low<=high){
            long long mid = low+(high-low)/2;
            long long sq = mid*mid;
            if(sq==x) return mid;
            else if(sq>x){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return high;
        
    }
};