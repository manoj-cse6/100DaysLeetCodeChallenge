class Solution {
public:
    bool sumGame(string num) {
        int lsum=0,rsum=0,ql=0,qr=0;
        int n=num.size();
        for(int i=0;i<n/2;i++)
        {
            if(num[i]=='?'){
                ql++;
            }
            else
            lsum+=num[i]-'0';
        }
        for(int i=n/2;i<n;i++)
        {
            if(num[i]=='?'){
                qr++;
            }
            else
            rsum+=num[i]-'0';
        }
        //int diff=abs(lsum-rsum);
        //int qd=(qr-ql);
        if((ql+qr)%2==1)
        return true;
        return (2*(lsum-rsum)!=9*(qr-ql));
    }
};