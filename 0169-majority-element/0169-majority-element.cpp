class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a=nums[0],count=1;
        for(int i=1;i<nums.size();i++){
            if(a==nums[i]) count++;
            else count--;
        if(count==0) {a=nums[i];
        count=1;}
        }
        return a;
    }
};