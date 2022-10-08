class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        vector<int> tmp = {nums1.begin(),nums1.begin()+m};
        int i=0,j=0;
        for(int k=0;k<m+n;k++){
            if(i>=m){
                nums1[k] = nums2[j];
                j++;
            }
            else if(j>=n){
                nums1[k] = tmp[i];
                i++;
            }
            else{
                if(tmp[i]<=nums2[j]){
                    nums1[k] = tmp[i];
                    i++;
                }else{
                    nums1[k] = nums2[j];
                    j++;
                }
            }
        }
    }
};