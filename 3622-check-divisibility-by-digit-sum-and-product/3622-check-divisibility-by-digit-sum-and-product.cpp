class Solution {
public:
    bool checkDivisibility(int n) {
        int product=1,sum=0,digit;
        int temp=n;
        while(n!=0){
            digit=n%10;
            sum+=digit;
            product*=digit;
            n/=10;
        }
        sum+=product;
        return temp%sum==0;
        
        
    }
};