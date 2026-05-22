class Solution {
public:
    bool isPalindrome(string s , int left , int right){
        if(left>right){
            return false;
        }
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void helper(string s , int index , vector<string>& curr , vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s , index , i)){
                curr.push_back(s.substr(index , i-index+1));
                helper(s , i+1 , curr , ans);
                curr.pop_back();

            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        helper(s , 0 , curr, ans);
        return ans;
        
    }
};
