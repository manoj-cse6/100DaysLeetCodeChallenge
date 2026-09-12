class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
            
            vector<string> m=
            {".-","-...","-.-.","-..",".","..-.","--.","....","..", ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",  "...","-","..-","...-",".--","-..-","-.--","--.."};
          unordered_set<string> answer;
          string temp;
          for (string a:words){
              temp="";
              for(char c:a){
                  temp+=m[c-'a'];
              }
              answer.insert(temp);
          }
          return answer.size();
                  
    }
};