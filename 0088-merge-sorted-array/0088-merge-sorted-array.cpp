class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int k=m+n-1;
        int x=m-1;
        int y=n-1;
        while(x>=0&&y>=0){
           if(nums1[x]<nums2[y]){
            nums1[k]=nums2[y];
            y--;
           }
           else if(nums1[x]>nums2[y]){
            nums1[k]=nums1[x];
            x--;
           }

           else{
            nums1[k]=nums1[x];
            k--;
            nums1[k]=nums2[y];
            x--;
            y--;
           }
           k--;
        }
        if(x<0){
           while(y>=0)
           {
            nums1[k]=nums2[y];
            y--;
            k--;
           }
        }
       




    }
};