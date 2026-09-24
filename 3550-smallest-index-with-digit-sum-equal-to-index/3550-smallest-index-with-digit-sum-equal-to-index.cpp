class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int sum,dig;
        for(int i=0;i<nums.size();i++){
            sum=0;
            while(nums[i]>0){
              
                dig=nums[i]%10;
                sum+=dig;
                nums[i]/=10;
            }
            if(sum==i)return i;
        }
        return -1;
    }
};