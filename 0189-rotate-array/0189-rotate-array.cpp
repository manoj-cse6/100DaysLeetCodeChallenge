class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k%=nums.size();
        int n=nums.size()-k;
        vector<int> answer;
        for(int i=n;i<nums.size();i++){
                   answer.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            answer.push_back(nums[i]);
        }
        for(int i=0;i<answer.size();i++){
            nums[i]=answer[i];
        }
    }
};