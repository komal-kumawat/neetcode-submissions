class Solution {
    public void dfs(char[][] grid , boolean[][] vis , int row , int col){
        int m = grid.length , n = grid[0].length;
        if(row<0 || col<0 || row>=m || col>=n|| grid[row][col]=='0' || vis[row][col]==true){
            return;
        }
        vis[row][col] = true;


        dfs(grid , vis , row+1 , col);
        dfs(grid , vis , row-1 , col);
        dfs(grid , vis , row , col+1);
        dfs(grid , vis , row , col-1);
    }
    public int numIslands(char[][] grid) {
        int m = grid.length , n = grid[0].length , count = 0;
        boolean[][] vis = new boolean[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid , vis , i , j);
                }
            }
        }
        return count;
        
    }
}
