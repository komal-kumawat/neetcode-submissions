class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() , n = matrix[0].size();
        int maxlen = m*n-1;
        int low = 0 , high = maxlen;
        while(low<=high){
            int mid = low+(high-low)/2;
            int ele = matrix[mid/n][mid%n];
            if(ele==target){
                return true;
            }else if(ele>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;

    }
};
