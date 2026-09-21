class Solution{
public:
vector<long long> resultArray(vector<int>& nums,int k){
vector<long long> dp(k),ans(k);
for(int num:nums){
vector<long long> next(k);
next[num%k]++;
for(int r=0;r<k;r++){
if(dp[r]){
int nr=(r*1LL*(num%k))%k;
next[nr]+=dp[r];
}
}
dp=next;
for(int r=0;r<k;r++) ans[r]+=dp[r];
}
return ans;
}
};