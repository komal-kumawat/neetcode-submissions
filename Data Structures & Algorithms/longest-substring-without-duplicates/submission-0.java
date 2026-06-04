class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character>seen = new HashSet<>();
        int left = 0 , maxlen = 0;
        for(int right = 0;right<s.length();right++){
            while(left<right && seen.contains(s.charAt(right))){
                seen.remove(s.charAt(left));
                left++;
            }
            seen.add(s.charAt(right));
            maxlen = Math.max(maxlen , seen.size());

        }
        return maxlen;
        
    }
}
