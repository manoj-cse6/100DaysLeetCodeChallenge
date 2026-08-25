class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> bad(n);

        for (int i = 1; i < n; i++)
            bad[i] = bad[i - 1] + ((nums[i] % 2) == (nums[i - 1] % 2));

        vector<bool> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(bad[r] == bad[l]);
        }

        return ans;
    }
};