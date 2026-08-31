class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini= 0;
        int maxi= 0;

       
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mini])
                mini = i;

            if (nums[i] > nums[maxi])
                maxi = i;
        }

        int left = min(mini, maxi);
        int right = max(mini, maxi);

        int front = right + 1;
        int back = n - left;
        int both = (left + 1) + (n - right);


        int answer=min({front, back, both});
        return answer;
    }
};