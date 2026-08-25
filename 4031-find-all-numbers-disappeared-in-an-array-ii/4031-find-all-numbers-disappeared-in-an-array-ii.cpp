class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int a=lower,b=upper;
        vector<vector<int>> answer;
        for(int x:temp){
            if(x<a) continue;
            if(x>b) break;
             if(x>a){
            
                answer.push_back({a,x-1});
            }
            a=x+1;
        }
        if(a<=b){
            answer.push_back({a,b});
        }
        return answer;
    }
};