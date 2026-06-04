class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {

        Deque<Integer> dq = new ArrayDeque<>();
        List<Integer> ans = new ArrayList<>();

        for (int right = 0; right < nums.length; right++) {

            // Remove smaller elements
            while (!dq.isEmpty() &&
                   nums[dq.peekLast()] < nums[right]) {
                dq.pollLast();
            }

            dq.offerLast(right);

            // Remove elements outside window
            while (!dq.isEmpty() &&
                   dq.peekFirst() <= right - k) {
                dq.pollFirst();
            }

            // Window formed
            if (right >= k - 1) {
                ans.add(nums[dq.peekFirst()]);
            }
        }

        int[] res = new int[ans.size()];

        for (int i = 0; i < ans.size(); i++) {
            res[i] = ans.get(i);
        }

        return res;
    }
}