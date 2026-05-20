class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , vector<int>>>q;
        for(auto point:points){
            int dist = point[0]*point[0]+point[1]*point[1];
            q.push({dist , point});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<vector<int>>ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
        
    }
};
