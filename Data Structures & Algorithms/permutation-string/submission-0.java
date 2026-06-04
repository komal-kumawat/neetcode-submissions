class Solution {
    public boolean checkInclusion(String s1, String s) {
        int k = s1.length();
        HashMap<Character , Integer>hash = new HashMap<>();
        for(char ch:s1.toCharArray()){
            if(hash.containsKey(ch)){
                hash.put(ch , hash.get(ch)+1);
            }else{
                hash.put(ch , 1);
            }

        }
        int left= 0;
        HashMap<Character , Integer>hash2 = new HashMap<>();
        for(int right = 0;right<s.length();right++){
            char ch = s.charAt(right);
            if(hash2.containsKey(ch)){
                hash2.put(ch , hash2.get(ch)+1);
            }else{
                hash2.put(ch ,1);
            }
            if(right-left+1>k){
                char remove = s.charAt(left);
                hash2.put(remove , hash2.get(remove)-1);
                if(hash2.get(remove)==0){
                    hash2.remove(remove);
                }
                left++;
            }
            if(hash.equals(hash2)) return true;
            
        }
        return false;
        
    }
}
