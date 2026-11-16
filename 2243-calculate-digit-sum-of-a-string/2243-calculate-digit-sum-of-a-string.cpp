class Solution{
    public:
    string digitSum(string s,int k){
        while(s.size()>k){
            string ans="";
            int sum=0,i=0;
            for(char c:s){
                sum+=c-'0';
                i++;
                if(i==k)
                {ans+=to_string(sum);
                sum=0;
                i=0;
                }
                }
                if(i>0)ans+=to_string(sum);
                s=ans;}
                return s;
                }
                };
