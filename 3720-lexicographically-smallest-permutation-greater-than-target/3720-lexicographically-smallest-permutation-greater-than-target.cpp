class Solution {
public:
    string lexGreaterPermutation(string s,string target) {
        int cnt[26]={};
        for(char c:s) cnt[c-'a']++;

        string ans;
        int n=s.size();

        for(int i=0;i<n;i++){
            int x=target[i]-'a';

            if(cnt[x]){
                cnt[x]--;
                ans+=target[i];
                continue;
            }

            for(int c=x+1;c<26;c++){
                if(cnt[c]){
                    ans+=char('a'+c);
                    cnt[c]--;

                    for(int k=0;k<26;k++)
                        while(cnt[k]--)
                            ans+=char('a'+k);

                    return ans;
                }
            }

            break;
        }

        for(int i=ans.size()-1;i>=0;i--){
            cnt[ans[i]-'a']++;

            int x=target[i]-'a';

            for(int c=x+1;c<26;c++){
                if(cnt[c]){
                    string res=target.substr(0,i);
                    res+=char('a'+c);
                    cnt[c]--;

                    for(int k=0;k<26;k++)
                        while(cnt[k]--)
                            res+=char('a'+k);

                    return res;
                }
            }
        }

        return "";
    }
};