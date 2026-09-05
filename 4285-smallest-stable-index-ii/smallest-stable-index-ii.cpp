class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
vector<int>r(n);
r[n-1]=nums[n-1];
for(int i=n-2;i>=0;i--)r[i]=min(r[i+1],nums[i]);
int l=nums[0];
for(int i=0;i<n;i++){
l=max(l,nums[i]);
if(l-r[i]<=k)return i;
}
return -1;
    }
};