class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        int i=0;
        for(;i<strs[0].length();i++){
            if(strs[0].charAt(i)!=strs[strs.length-1].charAt(i)){
                break;
            }
        }
        return strs[0].substring(0 , i);
    }
}