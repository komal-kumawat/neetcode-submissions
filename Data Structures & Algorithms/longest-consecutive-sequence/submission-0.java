class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer>seen = new HashSet<>();
        for(int num:nums){
            seen.add(num);
        }
        int maxcount = 0;
        for(int num:nums){
            if(!seen.contains(num-1)){
                int count = 0 , n = num;
                while(seen.contains(n)){
                    count++;
                    n++;
                }
                maxcount = Math.max(maxcount , count);
            }
        }
        return maxcount;
        
    }
}
