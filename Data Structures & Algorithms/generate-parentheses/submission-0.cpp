class Solution {
public:
    vector<string>ans;
    void helper(int n , int opencount, int closecount , string s){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(opencount<n){
            helper(n , opencount+1 , closecount , s+'(');
        }
        if(closecount<opencount){
            helper(n , opencount , closecount+1 , s+')');
        }

    }
    vector<string> generateParenthesis(int n) {
        helper(n , 0 , 0 , "");
        return ans;

        
    }
};
