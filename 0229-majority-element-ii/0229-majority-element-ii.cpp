class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        vector<int> answer;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            if(x.second>n/3) answer.push_back(x.first);
        }
        return answer;
    }
};