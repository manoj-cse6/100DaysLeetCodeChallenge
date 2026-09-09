class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
              int m=nums1.size(),n=nums2.size();
              vector<int> answer;
              for(int i=0;i<m;i++){
                answer.push_back(nums1[i]);
              }
              
              for(int i=0;i<n;i++){
                answer.push_back(nums2[i]);
              }
              sort(answer.begin(),answer.end());
              int index=answer.size()/2;
              double median=0;
              if(answer.size()%2==0){
                median=(answer[index]+answer[index-1])/2.0;
              }
              else 
              median = answer[index];
              return median;
    }
};