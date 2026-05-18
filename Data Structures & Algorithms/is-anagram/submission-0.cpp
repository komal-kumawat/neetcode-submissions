class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size()){
            return false;
        }
        unordered_map<char , int>hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]]+=1;

        }
        for(int j=0;j<t.size();j++){
            if(hash.find(t[j])==hash.end() || hash[t[j]]==0){
                return false;
            }
            hash[t[j]]-=1;
        }
        return true;
    }
};
