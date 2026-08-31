class Solution {
public:
    long long p(long long x,long long y){
        long long answer=1;
        while(y>0){
            if(y%2)
                answer=answer*x%1000000007;
            x=x*x%1000000007;
            y/=2;
        }
        return answer;
    }
    int sumDecoded(vector<long long>& nums) {
        long long answer=0;
        for(long long n:nums){
            int a=n%10;
             long long d=n/10;
            string s=to_string(d);
            long long x=stoi(s.substr(0,a));
            long long y=stoi(s.substr(a));
            answer=(answer+p(x,y))%1000000007;
        }
        return answer;
    }
};