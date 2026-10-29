class Solution {
public:
    string countAndSay(int n) {
        string rle="1";
        
        
        n--;
      while(n--){
        string temp="";
       
        for(int i=0;i<rle.size();i++){
            int j=i;
    while(j<rle.size() && rle[j]==rle[i]) j++;
    temp+=to_string(j-i);
    temp+=rle[i];
    i=j-1;
         }
         rle=temp;


      }
      return rle;


    }
};