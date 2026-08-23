class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
vector<int> answer(n,-1);
long long sum=0;
int size=2*k+1;
       if(2*k+1>n)return answer;
       for(int i=0;i<size;i++){
        sum+=nums[i];
       }
       answer[k]=sum/size;
        for(int i=size;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-size];

            int a=i-k;
            answer[a]=sum/size;
        }
        
        return answer;
    }
};