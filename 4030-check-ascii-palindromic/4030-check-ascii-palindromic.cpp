class Solution {
public:
    bool isPalindromic(string s) {
        string answer="";
        int a=0,l=0;
        for(char c:s){
            int a=(int)c;
            for(int i=7;i>=0;i--){
                answer+=((a>>i)&1)?'1':'0';
            }
        }
        int r=answer.size()-1;
        while(l<r){
            if(answer[l]!=answer[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};