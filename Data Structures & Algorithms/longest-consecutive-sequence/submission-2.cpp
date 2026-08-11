class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        
        int lastSmaller = INT_MIN;
        int longest = 1;
        int curr = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] - 1 == lastSmaller){
                curr++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller){
                curr = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, curr);
        }

        return longest;
    }
};
