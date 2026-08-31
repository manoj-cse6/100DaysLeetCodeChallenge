class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF=1e9;
        vector<int> dp(sum+1,INF);
        dp[0]=0;
        for(int x:nums){
            vector<pair<int,int>> v;
              for(int y=x,c=0;y<=sum;y*=2,c++)
                  v.push_back({y,c});
            for(int y=x/2,c=1;y;y/=2,c++)
                v.push_back({y,c});
            for(int s=sum;s>=0;s--){
                for(auto[y,c]:v){
                    if(s>=y)
                        dp[s]=min(dp[s],dp[s-y]+c);
            }
            }
        }
        return dp[sum]==INF?-1:dp[sum];
    }
};