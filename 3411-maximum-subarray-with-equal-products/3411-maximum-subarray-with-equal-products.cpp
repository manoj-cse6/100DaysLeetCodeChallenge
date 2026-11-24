class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 2, l = 0, mask = 0;
        int p[] = {2, 3, 5, 7};

        for(int r = 0; r < nums.size(); r++) {
            int m = 0;
            for(int i = 0; i < 4; i++)
                if(nums[r] % p[i] == 0) m |= (1 << i);

            while(mask & m) {
                int x = nums[l++];
                for(int i = 0; i < 4; i++)
                    if(x % p[i] == 0) mask ^= (1 << i);
            }

            mask |= m;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};