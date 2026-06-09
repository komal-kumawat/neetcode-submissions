class Solution {
    public void dfs(int[][] heights, boolean[][] vis, int row, int col, int prevHeight) {
        int m = heights.length;
        int n = heights[0].length;

        if (row < 0 || col < 0 || row >= m || col >= n || vis[row][col]
            || heights[row][col] < prevHeight) {
            return;
        }

        vis[row][col] = true;

        dfs(heights, vis, row + 1, col, heights[row][col]);
        dfs(heights, vis, row - 1, col, heights[row][col]);
        dfs(heights, vis, row, col + 1, heights[row][col]);
        dfs(heights, vis, row, col - 1, heights[row][col]);
    }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> ans = new ArrayList<>();
        int m = heights.length, n = heights[0].length;
        boolean[][] Pacific = new boolean[m][n];
        boolean[][] Atlantic = new boolean[m][n];

        for (int c = 0; c < n; c++) {
            dfs(heights, Pacific, 0, c , heights[0][c]);
            dfs(heights, Atlantic, m - 1, c , heights[m-1][c]);
        }
        for (int r = 0; r < m; r++) {
            dfs(heights, Pacific, r, 0 , heights[r][0]);
            dfs(heights, Atlantic, r, n - 1 , heights[r][n-1]);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (Pacific[i][j] && Atlantic[i][j]) {
                    ans.add(Arrays.asList(i, j));
                }
            }
        }
        return ans;
    }
}
