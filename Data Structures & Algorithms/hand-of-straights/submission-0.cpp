class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0) {
            return false;
        }

        map<int,int> freq;

        for(int num : hand) {
            freq[num]++;
        }

        while(!freq.empty()) {

            int start = freq.begin()->first;

            for(int i = start; i < start + groupSize; i++) {

                if(freq.find(i) == freq.end()) {
                    return false;
                }

                freq[i]--;

                if(freq[i] == 0) {
                    freq.erase(i);
                }
            }
        }

        return true;
    }
};