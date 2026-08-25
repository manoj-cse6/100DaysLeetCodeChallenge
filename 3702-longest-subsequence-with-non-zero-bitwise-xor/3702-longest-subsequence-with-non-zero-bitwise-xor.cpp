class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        bool Zero=false;
        for(int p:nums){
            x^=p;
            if(p!=0)Zero=true;
        }
        if(x!=0)return n;
        return Zero?n-1:0;
    }
};