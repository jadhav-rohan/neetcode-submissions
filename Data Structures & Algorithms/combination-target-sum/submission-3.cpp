class Solution {
   public:
    void func(int idx, vector<int> &nums, vector<int> &temp, int target, int n,
              vector<vector<int>>& ans) {
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(idx == n || target < 0){
            return;
        }
        if (nums[idx] <= target) {
            temp.push_back(nums[idx]);
            func(idx, nums, temp, target - nums[idx], n, ans);
            temp.pop_back();
        }
        func(idx + 1, nums, temp, target, n, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(0, nums, temp, target, nums.size(), ans);

        return ans;
    }
};
