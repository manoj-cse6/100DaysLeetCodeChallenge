class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;

        for (int num : nums)
            f[num]++;

        vector<pair<int, int>> e;

        for (auto [num, count] : f)
            e.push_back({count, num});

        sort(e.rbegin(), e.rend());

        vector<int> answer;

        for (int i = 0; i < k; i++)
            answer.push_back(e[i].second);

        return answer;
    }
};