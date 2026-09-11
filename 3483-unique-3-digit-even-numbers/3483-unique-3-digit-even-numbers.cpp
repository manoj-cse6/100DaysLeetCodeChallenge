class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        for(int x:digits) { mp[x]++; }
        int answer=0;
        for(int i=1;i<=9;i++) {
            if(!mp[i]) 
            {continue;}
            mp[i]--;
            for(int j=0;j<=9;j++) {
                if(!mp[j])
                 {continue;}
                mp[j]--;
                for(int k=0;k<=8;k+=2){
                    if(mp[k])
                     {answer++;}
                     }
                       mp[j]++;
            }
            mp[i]++;
        }
        return answer;
    }
};