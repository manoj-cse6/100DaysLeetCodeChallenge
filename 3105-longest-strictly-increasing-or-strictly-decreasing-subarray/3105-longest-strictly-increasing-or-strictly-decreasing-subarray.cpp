class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int icount=1,dcount=1,answer=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                icount++;
                dcount=1;}
            else if(nums[i]==nums[i+1]){
                icount=1;
            dcount=1;
            }
            else {
                dcount++;
                icount=1;
            }
            int maxi=max(icount,dcount);
            answer=max(answer,maxi);

        }
        return answer;
    }
};