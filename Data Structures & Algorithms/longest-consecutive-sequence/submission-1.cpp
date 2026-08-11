class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int prevMin = nums[0];
        int longest = 1;
        int count = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == prevMin){

            }
            else if(prevMin + 1 == nums[i]){
                count++;
                prevMin = nums[i];
            }
            else{
                count = 1;
                prevMin = nums[i];
            }
            longest = max(longest, count);
        }

        return longest;
    }
};
