class Solution {
public:
    int start = 0;
    int maxlen = 1;
    void expand(string s , int left , int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            int len = right-left+1;
            if(len>maxlen){
                maxlen = len;
                start = left;
                
            }

            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        int n= s.size();
        for(int i=0;i<n;i++){
            expand(s , i , i);
            expand(s , i , i+1);
        }
        return s.substr(start , maxlen);
        
    }
};
