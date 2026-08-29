class Solution {
   public:
    void func(vector<int>& nums, int idx, set<vector<int>>& s, vector<int>& temp) {
        if (idx >= nums.size()) {
            s.insert({temp});
            return;
        }

        temp.push_back(nums[idx]);
        func(nums, idx + 1, s, temp);
        temp.pop_back();
        func(nums, idx + 1, s, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> temp;

        func(nums, 0, s, temp);

        for (auto itr : s) {
            ans.push_back(itr);
        }

        return ans;
    }
};
