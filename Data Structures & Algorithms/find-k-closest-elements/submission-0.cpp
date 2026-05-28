class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int , int>>q;
        for(int num:arr){
            q.push({abs(num-x) , num});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<int>ans;
        while(q.size()>0){
            ans.push_back(q.top().second);
            q.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};