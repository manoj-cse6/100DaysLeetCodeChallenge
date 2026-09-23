class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0)
            return -1;
        if (target == 0)
            return n;
        int l = 0, sum = 0, longest = -1;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > target && l <= r)
                sum -= nums[l++];
            if (sum == target)
                longest = max(longest, r - l + 1);
        }
        return longest == -1 ? -1 : n - longest;
    }
};