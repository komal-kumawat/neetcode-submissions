class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int , int>hash;
        for(int num:nums){
        hash[num]+=1;
        }
        priority_queue<pair<int ,int>, vector<pair<int , int>> , greater<pair<int , int>>>q;
        for(auto& [num , freq]:hash){
            q.push({freq , num});
            while(q.size()>k){
                q.pop();
            }
        }
        while(q.size()>0){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;

    }
};
