class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();vector<vector<int>>g(n),t(n);vector<int>a(n),last(26,-1);
for(int i=1;i<n;i++)g[parent[i]].push_back(i);
function<void(int)>dfs=[&](int u){
int c=s[u]-'a',v=last[c];last[c]=u;
if(u)t[v==-1?parent[u]:v].push_back(u);
for(int x:g[u])dfs(x);
last[c]=v;
};
dfs(0);
function<int(int)>calc=[&](int u){
a[u]=1;for(int v:t[u])a[u]+=calc(v);
return a[u];
};
calc(0);return a;
    }
};