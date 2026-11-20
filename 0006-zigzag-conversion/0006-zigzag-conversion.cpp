class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int i=0,move=0;
        if(numRows==1 || numRows>=s.size()) return s;
        for(char c:s){
            rows[i]+=c;
            if(i==0)move=1;
            if(i==numRows-1)move=-1;
            i+=move;
        }
        string ans;
        for(string t:rows)ans+=t;
        return ans;
    }
};