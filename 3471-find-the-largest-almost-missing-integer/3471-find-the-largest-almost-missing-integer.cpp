class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = -1;
        for (int i = 0; i <= nums.size() - k; i++) {

            unordered_set<int> s;
            for (int j = i; j < i + k; j++) {

                s.insert(nums[j]);
            }
            for (int x : s) {
                mp[x]++;
            }
        }
        for (auto p : mp) {
            if (p.second == 1)
                ans = max(ans, p.first);
        }
    
    return ans;
}
};