class Solution {
public:

    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {

        vector<int> ans;

        for(int query : queries) {

            int mini = INT_MAX;

            for(auto &interval : intervals) {

                int left = interval[0];
                int right = interval[1];

                // query inside interval
                if(left <= query &&
                   query <= right) {

                    mini = min(mini,
                               right - left + 1);
                }
            }

            if(mini == INT_MAX) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(mini);
            }
        }

        return ans;
    }
};