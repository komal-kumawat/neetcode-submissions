class Solution {
public:

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& vis,
             int i,
             int j,
             int prevHeight) {

        if(i < 0 || j < 0 ||
           i >= heights.size() ||
           j >= heights[0].size() ||
           vis[i][j] ||
           heights[i][j] < prevHeight) {
            return;
        }

        vis[i][j] = true;

        dfs(heights, vis, i - 1, j, heights[i][j]); // up
        dfs(heights, vis, i + 1, j, heights[i][j]); // down
        dfs(heights, vis, i, j - 1, heights[i][j]); // left
        dfs(heights, vis, i, j + 1, heights[i][j]); // right
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top row
        for(int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, heights[0][j]);
        }

        // Pacific: left column
        for(int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, heights[i][0]);
        }

        // Atlantic: bottom row
        for(int j = 0; j < n; j++) {
            dfs(heights, atlantic, m - 1, j, heights[m - 1][j]);
        }

        // Atlantic: right column
        for(int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n - 1, heights[i][n - 1]);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};