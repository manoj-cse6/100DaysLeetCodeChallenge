class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
      int mini = INT_MAX;

    for (int x : nums1)
        if (x & 1) mini = min(mini, x);

    if (mini == INT_MAX) return true;

    for (int x : nums1)
        if (!(x & 1) && x <= mini)
            return false;

    return true;   
    }
};