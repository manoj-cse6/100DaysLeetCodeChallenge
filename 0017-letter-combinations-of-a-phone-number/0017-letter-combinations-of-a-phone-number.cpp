class Solution {
public:
    vector<string> letterCombinations(string digits) {
         vector<string> mp={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans={""};

        for(char d:digits){
            vector<string> temp;
            for(string s:ans){
                for(char c:mp[d-'2'])
                    temp.push_back(s+c);
            }
            ans=temp;
        }

        return ans.size()==1 && ans[0]==""?vector<string>():ans;
    }
};