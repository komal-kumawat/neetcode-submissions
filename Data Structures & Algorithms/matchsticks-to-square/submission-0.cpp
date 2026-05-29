class Solution {
public:
    bool solve(int idx, vector<int>& nums,
               vector<int>& sides, int target) {

        if (idx == nums.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {

            if (sides[i] + nums[idx] <= target) {

                sides[i] += nums[idx];

                if (solve(idx + 1, nums, sides, target))
                    return true;

                sides[i] -= nums[idx];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum = 0;

        for (int x : matchsticks)
            sum += x;

        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<int> sides(4, 0);

        return solve(0, matchsticks, sides, target);
    }
};