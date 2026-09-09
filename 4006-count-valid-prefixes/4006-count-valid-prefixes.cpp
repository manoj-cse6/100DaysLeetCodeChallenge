class Solution {
public:
    int countValidPrefixes(string s) {
        int ans=0,x=0;
        for(char c:s){
            x+=(c=='1'?1:-1);
            if(abs(x)<=1) ans++;
        }
        return ans;
    }
};