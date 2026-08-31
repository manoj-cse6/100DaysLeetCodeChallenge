class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> s,x;
        for(int i=0;i<nums.size();i++)
            {
                if(i&&s.count(nums[i])&&nums[i]!=nums[i-1])
                    x.insert(nums[i]);
                s.insert(nums[i]);
                
            }
    
    int answer=s.size()-x.size();
        return answer;
    }
};