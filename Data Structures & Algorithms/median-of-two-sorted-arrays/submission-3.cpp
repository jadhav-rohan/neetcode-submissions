class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 && nums2.size() == 0) {
            return -0.5;
        }

        int i = 0, j = 0;

        int totalSize = nums1.size() + nums2.size();
        int idx1 = totalSize / 2, idx2 = idx1 - 1, count = 0;
        int el1 = -1, el2 = -1;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                if (count == idx1) el1 = nums1[i];
                if (count == idx2) el2 = nums1[i];
                i++;
                count++;
            } else {
                if (count == idx1) el1 = nums2[j];
                if (count == idx2) el2 = nums2[j];
                j++;
                count++;
            }
        }

        while (i < nums1.size()) {
            if (count == idx1) el1 = nums1[i];
            if (count == idx2) el2 = nums1[i];
            i++;
            count++;
        }

        while (j < nums2.size()) {
            if (count == idx1) el1 = nums2[j];
            if (count == idx2) el2 = nums2[j];
            j++;
            count++;
        }

        if(totalSize % 2 == 0){
            double ans = (double(el1) + double(el2)) / (2.0);
            return ans;
        }

        return el1;
    }
};
