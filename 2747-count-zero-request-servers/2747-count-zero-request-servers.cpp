#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution{
public:
vector<int>countServers(int n,vector<vector<int>>&logs,int x,vector<int>&queries){
int m=queries.size();
vector<pair<int,int>>q(m);
for(int i=0;i<m;++i)q[i]={queries[i],i};
sort(q.begin(),q.end());
sort(logs.begin(),logs.end(),[](const vector<int>&a,const vector<int>&b){
return a[1]<b[1];
});
vector<int>ans(m);
map<int,int>cnt;
int l=0,r=0;
for(int i=0;i<m;++i){
int qtime=q[i].first;
int idx=q[i].second;
int start=qtime-x;
while(r<logs.size()&&logs[r][1]<=qtime){
cnt[logs[r][0]]++;
r++;
}
while(l<logs.size()&&logs[l][1]<start){
int id=logs[l][0];
if(--cnt[id]==0)cnt.erase(id);
l++;
}
ans[idx]=n-cnt.size();
}
return ans;
}
};
