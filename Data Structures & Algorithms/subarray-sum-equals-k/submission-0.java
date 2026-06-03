class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer , Integer>hash = new HashMap<>();
        int count = 0 , sum = 0;
        hash.put(sum , 1);
        for(int num:nums){
            sum+=num;
            int comp = sum -k;
            if(hash.containsKey(comp)){
                count+=hash.get(comp);
            }
            hash.put(sum, hash.getOrDefault(sum, 0) + 1);



        }
        return count;
        
    }
}