class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> hash1, hash2;

        for(char ch : t) {
            hash1[ch]++;
        }

        int req = t.size();
        int count = 0;

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {

            hash2[s[right]]++;

            // count only useful chars
            if(hash2[s[right]] <= hash1[s[right]]) {
                count++;
            }

            // valid window
            while(count == req) {

                // update answer
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // shrink
                hash2[s[left]]--;

                if(hash2[s[left]] < hash1[s[left]]) {
                    count--;
                }

                left++;
            }
        }

        if(minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};