class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char , int>hash1 , hash2;
        for(char ch:s1){
            hash1[ch]++;
        }
        int left = 0;
        int k = s1.size();
        for(int right = 0;right<s2.size();right++){
            hash2[s2[right]]++;
            if(right==k-1){
                if(hash1==hash2){
                    return true;
                }
            }else if(right>k-1){
                hash2[s2[left]]--;
                if(hash2[s2[left]]==0){
                    hash2.erase(s2[left]);

                }
                left++;
                if(hash1==hash2){
                    return true;
                }
            }

        }
        return false;
    }
};
