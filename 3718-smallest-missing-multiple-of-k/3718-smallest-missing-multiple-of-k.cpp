class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(),nums.end());
        int i=1;
        while(true){
            if(s.count(k*i)==0) return k*i;
            i++;
        }
        return -1;
    }
};