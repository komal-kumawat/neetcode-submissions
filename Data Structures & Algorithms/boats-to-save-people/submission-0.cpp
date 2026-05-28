class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        int low = 0 , high = people.size()-1;
        int count = 0;
        while(low<=high){
            int sum = people[low]+people[high];
            if(sum<=limit){
                count++;
                low++;
                high--;
            }
            else{
                count++;
                high--;
            }


        }
        return count;
    }

};