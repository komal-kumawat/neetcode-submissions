class Solution {
public:
    bool helper(vector<vector<char>>&board , string word , int i , int j , vector<vector<bool>>&visited , int index){
        if(index==word.size()){
            return true;
        }
        if(i<0 ||j<0 || i>=board.size() || j>=board[0].size()||index>=word.size() || board[i][j]!= word[index] || visited[i][j]==true){
            return false;
        }
        visited[i][j]= true;
        bool left = helper(board , word ,i , j-1 , visited , index+1 );
        bool right = helper(board , word ,i , j+1 , visited , index+1 );
        bool top= helper(board , word ,i-1 , j , visited , index+1 );
        bool bottom = helper(board , word ,i+1 , j , visited , index+1 );
        visited[i][j] = false;
        return left||right||top||bottom;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>visited(board.size() , vector<bool>(board[0].size() , false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(visited[i][j]==false){
                    if(helper(board , word , i , j , visited , 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
