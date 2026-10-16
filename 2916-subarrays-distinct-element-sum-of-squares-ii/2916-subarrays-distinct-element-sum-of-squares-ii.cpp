class Solution {
    static const int MOD = 1000000007;

    vector<long long> sum, sq, lazy;
    int n;

    void update(int node, int start, int end, int l, int r) {
        if (l > end || r < start)
            return;

        if (l <= start && end <= r) {
            long long len = end - start + 1;
            sq[node] = (sq[node] + 2 * sum[node] + len) % MOD;
            sum[node] = (sum[node] + len) % MOD;
            lazy[node]++;
            return;
        }

        push(node, start, end);

        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r);
        update(node * 2 + 1, mid + 1, end, l, r);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

    void push(int node, int start, int end) {
        if (lazy[node] == 0 || start == end)
            return;

        int mid = (start + end) / 2;
        long long d = lazy[node];

        apply(node * 2, mid - start + 1, d);
        apply(node * 2 + 1, end - mid, d);

        lazy[node] = 0;
    }

    void apply(int node, long long len, long long d) {
        long long oldSum = sum[node];

        sq[node] = (sq[node] + 2 * d % MOD * oldSum
                    + (d * d % MOD) * len) % MOD;

        sum[node] = (sum[node] + d * len) % MOD;
        lazy[node] = (lazy[node] + d) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int l = last.count(nums[i]) ? last[nums[i]] + 1 : 0;

            update(1, 0, n - 1, l, i);

            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};