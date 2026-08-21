class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = INT_MAX;

        int start = 0, end = nums.size() - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[start] <= nums[end]){
                return min(ans, nums[start]);
            }

            if(nums[start] <= nums[mid]){
                ans = min(nums[start], ans);
                start = mid + 1;
            }
            else{
                ans = min(nums[mid], ans);
                end = mid - 1;
            }
        }
        return ans;
    }
};
