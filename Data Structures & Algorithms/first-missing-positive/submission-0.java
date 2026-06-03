class Solution {
    public int firstMissingPositive(int[] nums) {
        Set<Integer>seen = new HashSet<Integer>();
        for(int num:nums){
            if(num>0){
                seen.add(num);
            }
        }
        int i =1;
        while(seen.contains(i)){
            i++;
        }
        return i;

        
    }
}