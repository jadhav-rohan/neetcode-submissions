class Solution {
   public:
    void func(vector<int>& nums, int n, vector<vector<int>>& ans, vector<int>& temp, int idx) {
        ans.push_back(temp);

        for (int i = idx; i < n; i++) {
            if (i != idx && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            func(nums, n, ans, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size(), idx = 0;
        sort(nums.begin(), nums.end());

        func(nums, n, ans, temp, idx);

        return ans;
    }
};
