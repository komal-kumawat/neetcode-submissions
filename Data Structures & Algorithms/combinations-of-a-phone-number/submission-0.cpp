class Solution {
public:
    unordered_map<char , string>hash = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    vector<string >ans;
    void helper(string digits , int index , string curr){
        if(curr.size()==digits.size()){
            ans.push_back(curr);
            return ;
        }
        string s = hash[digits[index]];
        for(int i=0;i<s.size();i++){
            curr+=s[i];
            helper(digits , index+1 , curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return ans;
        }
        helper(digits , 0 , "");
        return ans;
        
    }
};
