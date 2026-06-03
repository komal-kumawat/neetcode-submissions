class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer , Integer>hash = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int num = nums[i];
            int comp = target-num;
            if(hash.containsKey(comp)){
                return new int[]{hash.get(comp)+1 , i+1};
            }
            hash.put(num , i);
        }
        return new int[]{};
        
        
    }
}
