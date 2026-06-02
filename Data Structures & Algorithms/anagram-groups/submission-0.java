class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String , List<String>>hash = new HashMap<>();
        for(int i=0;i<strs.length;i++){
            String s = strs[i];
            char[] arr = s.toCharArray();
            Arrays.sort(arr);
            String sorted = new String(arr);

            hash.putIfAbsent(sorted , new ArrayList<>());
            hash.get(sorted).add(strs[i]);
        }
        return new ArrayList<>(hash.values());
        
    }
}
