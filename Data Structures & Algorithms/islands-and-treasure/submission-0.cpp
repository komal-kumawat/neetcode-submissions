class Solution {
public:
    void dfs(vector<vector<int>>&grid , int i , int j , int dist){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1 || dist>grid[i][j]){
            return ;
        }
        grid[i][j] = min(grid[i][j] , dist);
        dfs(grid , i , j-1 , dist+1);
        dfs(grid , i , j+1 , dist+1);
        dfs(grid , i+1 , j , dist+1);
        dfs(grid , i-1 , j , dist+1);

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    dfs(grid , i , j , 0);
                }
            }
        }

        
    }
};
