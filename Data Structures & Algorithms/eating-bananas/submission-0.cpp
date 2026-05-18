class Solution {
public:
    bool helper(vector<int>&piles , int h , int k){
        int time = 0 ;
        for(int i=0;i<piles.size();i++){
            time+=(piles[i]+k-1)/k;
            if(time>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = 0;
        for(int num:piles){
            maxi = max(maxi , num);
        }
        int low = 1 , high = maxi;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            bool check = helper(piles , h , mid);
            if(check){
                ans = mid;
                high = mid-1;

            }else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};
