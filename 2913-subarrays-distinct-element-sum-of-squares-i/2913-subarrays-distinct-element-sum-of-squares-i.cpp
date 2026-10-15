class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size(),temp;
        long long sum=0;
        for(int i=0;i<n;i++){
            unordered_set<int> a;
            for(int j=i;j<n;j++){
                a.insert(nums[j]);
                temp=a.size();
                sum+=temp*temp;

            }
        }
        return sum;
        
    }
};