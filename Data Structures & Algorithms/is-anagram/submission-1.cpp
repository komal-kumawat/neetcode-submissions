class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int freq[26] = {0};
        for(auto ch:s){
            freq[ch-'a']++;
        }
        for(auto ch:t){
            if(freq[ch-'a']>0){
                freq[ch-'a']--;
                
            }else{
                return false;
            }
        }
        return true;
    }
};
