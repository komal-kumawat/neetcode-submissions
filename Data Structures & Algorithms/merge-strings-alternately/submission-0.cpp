class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size() , n = word2.size();
        int i=0 , j = 0;
        string ans = "";
        while(i<m && j<n){
            ans+=word1[i++];
            ans+=word2[j++];
        }
        if(i<m){
            ans+=word1.substr(i , m-i+1);
        }
        if(j<n){
            ans+=word2.substr(j , n-j+1);
        }
        return ans;
    }
};