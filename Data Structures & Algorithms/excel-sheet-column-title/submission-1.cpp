class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n>0){
            n--;
            int rem = n%26;

            ans = char('A'+rem)+ans;
            n = n/26;
        }
        return ans;
        
    }
};