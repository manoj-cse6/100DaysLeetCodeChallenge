#include <vector>
class Solution {
public:
int minCost(std::vector<std::vector<int>>& grid) {
int m=grid.size();
int n=grid[0].size();
std::vector<std::vector<bool>> dp(n,std::vector<bool>(1024,false));
dp[0][grid[0][0]]=true;
for(int i=0;i<m;++i){
for(int j=0;j<n;++j){
if(i==0&&j==0)continue;
int val=grid[i][j];
std::vector<bool> cur(1024,false);
for(int k=0;k<1024;++k){
if(i>0&&dp[j][k])cur[k^val]=true;
if(j>0&&dp[j-1][k])cur[k^val]=true;
}
dp[j]=std::move(cur);
}
}
for(int k=0;k<1024;++k){
if(dp[n-1][k])return k;
}
return 0;
}
};
