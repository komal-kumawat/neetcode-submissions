class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<char>seen;
        int maxlen = 0;
        for(int right = 0;right<s.size();right++){
            while(left<right and seen.count(s[right])){
                seen.erase(s[left++]);
            }
            seen.insert(s[right]);
            maxlen = max(maxlen , right-left+1);

        }
        return maxlen;
    }
};
