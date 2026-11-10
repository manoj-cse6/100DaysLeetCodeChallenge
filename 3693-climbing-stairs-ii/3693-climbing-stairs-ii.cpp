class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
       long long a=0,b=LLONG_MAX,c=LLONG_MAX;
        for(int i=1;i<=n;i++){
            long long d=LLONG_MAX;
            if(a!=LLONG_MAX)d=min(d,a+costs[i-1]+1);
            if(b!=LLONG_MAX)d=min(d,b+costs[i-1]+4);
            if(c!=LLONG_MAX)d=min(d,c+costs[i-1]+9);
            c=b;
            b=a;
            a=d;
        }
        return a;
    }
};