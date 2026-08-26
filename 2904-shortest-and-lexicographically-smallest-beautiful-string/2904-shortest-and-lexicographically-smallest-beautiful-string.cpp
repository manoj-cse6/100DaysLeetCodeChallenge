class Solution{
public:
    string shortestBeautifulSubstring(string s,int k){
        int l=0,cnt=0;
        string answer="";
        for(int r=0;r<s.size();r++){
            if(s[r]=='1') cnt++;
            while(cnt==k){
                string temp=s.substr(l,r-l+1);
                if(answer==""||temp.size()<answer.size()||(temp.size()==answer.size()&&temp<answer))
                    answer=temp;
                if(s[l]=='1') cnt--;
                l++;
            }
        }
        return answer;
    }
};