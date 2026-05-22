class Solution {
public:

    vector<vector<string>> ans;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // check upper column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        // upper left diagonal
        int i = row;
        int j = col;

        while(i >= 0 && j >= 0) {

            if(board[i][j] == 'Q') {
                return false;
            }

            i--;
            j--;
        }

        // upper right diagonal
        i = row;
        j = col;

        while(i >= 0 && j < n) {

            if(board[i][j] == 'Q') {
                return false;
            }

            i--;
            j++;
        }

        return true;
    }

    void helper(vector<string>& board, int row, int n) {

        // base case
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {

            if(isSafe(board, row, col, n)) {

                // choose
                board[row][col] = 'Q';

                // explore
                helper(board, row + 1, n);

                // backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        helper(board, 0, n);

        return ans;
    }
};