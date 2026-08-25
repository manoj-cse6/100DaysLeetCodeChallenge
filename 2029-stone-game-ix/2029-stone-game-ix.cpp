class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> c(3);
        for(int i:stones)
        {
            c[i%3]++;
        }
        int c1=c[0];
        int c2=c[1];
        int c3=c[2];
        if(c1%2==0){
            return c2>0&&c3>0;
        }
        return (abs(c2-c3)>2);
    }
};