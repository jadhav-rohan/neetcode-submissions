class Solution {
public:
    void func(vector<int>& nums, int n, vector<vector<int>> &ans, vector<int> &temp, set<vector<int>> &s, int idx){
        if(idx >= n){
            s.insert({temp});
            return;
        }

        temp.push_back(nums[idx]);
        func(nums, n, ans, temp, s, idx + 1);
        temp.pop_back();
        func(nums, n, ans, temp, s, idx + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> s;
        int n = nums.size(), idx = 0;
        sort(nums.begin(), nums.end());

        func(nums, n, ans, temp, s, idx);
        for(auto itr: s){
            ans.push_back(itr);
        }

        return ans;
    }
};
