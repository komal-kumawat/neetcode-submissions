class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int count1 = 0 , count2 = 0 , ans1 = 0 , ans2 = 0 , n = nums.length;
        for(int num:nums){
            if(count1==0 ){
                ans1 = num;
                count1 = 1;
            }else if(count2==0 && num!=ans1 ){
                ans2 = num;
                count2 = 1;
            }else if(num==ans1){
                count1++;
            }else if(num==ans2){
                count2++;
            }else{
                count1--;
                count2--;
            }

        }
        count1 = 0 ;
        count2 = 0;
        for(int num:nums){
            if(num==ans1) count1++;
            else if(num==ans2) count2++;
        }
        
        List<Integer> result = new ArrayList<>();

        if (count1 > n / 3) result.add(ans1);
        if (count2 > n / 3) result.add(ans2);

        return result;

        
    }
}