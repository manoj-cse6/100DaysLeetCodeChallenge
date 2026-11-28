class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
vector<int>freq(n+1);
int min_price=2e9;
for(auto&x:items)freq[x[0]]++,min_price=min(min_price,x[1]);
vector<int>div_count(n+1);
for(int f=1;f<=n;f++){
if(!freq[f])continue;
for(int m=f;m<=n;m+=f)div_count[f]+=freq[m];
}
vector<pair<int,int>>a;
for(auto&x:items)a.push_back({x[1],div_count[x[0]]-1});
sort(a.begin(),a.end());
long long rem=budget,ans=0;
for(auto [p,g]:a){
if(p>=2LL*min_price)break;
if(g<=0)continue;
long long k=min((long long)g,rem/p);
ans+=k*2;
rem-=k*p;
if(k<g)break;
}
return ans+rem/min_price;
    }
};