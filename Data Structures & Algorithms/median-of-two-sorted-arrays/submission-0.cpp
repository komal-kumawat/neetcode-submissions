class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        // always binary search on smaller array
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int total = m + n;
        int leftSize = (total + 1) / 2;

        int low = 0;
        int high = m;

        while(low <= high) {

            int cut1 = low + (high - low) / 2;

            int cut2 = leftSize - cut1;

            int l1 = (cut1 == 0)
                     ? INT_MIN
                     : nums1[cut1 - 1];

            int l2 = (cut2 == 0)
                     ? INT_MIN
                     : nums2[cut2 - 1];

            int r1 = (cut1 == m)
                     ? INT_MAX
                     : nums1[cut1];

            int r2 = (cut2 == n)
                     ? INT_MAX
                     : nums2[cut2];

            // correct partition
            if(l1 <= r2 && l2 <= r1) {

                // odd length
                if(total % 2 == 1) {
                    return max(l1, l2);
                }

                // even length
                return (max(l1,l2) + min(r1,r2)) / 2.0;
            }

            // move left
            else if(l1 > r2) {
                high = cut1 - 1;
            }

            // move right
            else {
                low = cut1 + 1;
            }
        }

        return 0;
    }
};