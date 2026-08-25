class Solution {
public:
    vector<int> Fac(int x){
       vector<int> f;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                f.push_back(i);
                while(x%i==0)
                    x/=i; 
            }
                
        }
        if(x>1) f.push_back(x);

        return f;
    }
    int longestSubarray(vector<int>& nums, int k) {
          unordered_map <int,int> mp;
        int l=0,answer=0;
        for(int r=0;r<nums.size();r++){
            for(int a:Fac(nums[r])){
                mp[a]++;
            }
            while(mp.size()>k){
                for(int a:Fac(nums[l]))
                    {
                        int v=--mp[a];
                        if(v==0) mp.erase(a);
                    }
                l++;
            }
            answer=max(answer,r-l+1);
        }

      return answer;
        
    }
};