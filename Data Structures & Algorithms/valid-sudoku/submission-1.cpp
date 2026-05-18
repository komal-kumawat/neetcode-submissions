class Solution {
public:
    bool isValid(vector<vector<char>>&board , int row , int col , char ch){
        for(int i=0;i<9;i++){
            if((i!=col && board[row][i]==ch) || (i!=row && board[i][col]==ch)){
                return false;
            }
        }
            int startRow = (row/3)*3 , startCol = (col/3)*3;
            for(int i=startRow ;i<startRow+3;i++){
                for(int j=startCol;j<startCol+3;j++){
                    if((i!=row || j!=col ) && board[i][j]==ch){
                        return false;
                    }
                }
            }
            return true;
        
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isValid(board , i , j , board[i][j])){
                        return false;
                    }
                }

            }
        }
        return true;
        
    }
};
