class Solution {
public:
    int count = 0;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // upper column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        // upper-left diagonal
        int i = row;
        int j = col;

        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // upper-right diagonal
        i = row;
        j = col;

        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q')
                return false;

            i--;
            j++;
        }

        return true;
    }

    void helper(vector<string>& board, int row, int n) {

        if(row == n) {
            count++;
            return;
        }

        for(int col = 0; col < n; col++) {

            if(isSafe(board, row, col, n)) {

                board[row][col] = 'Q';

                helper(board, row + 1, n);

                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        helper(board, 0, n);

        return count;
    }
};