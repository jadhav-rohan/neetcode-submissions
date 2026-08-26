class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> combine;
        if(nums1.size() == 0 && nums2.size() == 0){
            return -0.5;
        }
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                combine.push_back(nums1[i]);
                i++;
            }
            else{
                combine.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()){
            combine.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()){
            combine.push_back(nums2[j]);
            j++;
        }

        int s = combine.size();

        if(s % 2 == 1){
            return (combine[s/2]);
        }else{
            double ans = (double(combine[s/2]) + double(combine[(s/2) - 1])) / (2.0);
            return ans;

        }

        return 0.0;
    }
};
