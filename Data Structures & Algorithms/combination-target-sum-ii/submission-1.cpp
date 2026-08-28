class Solution {
   public:
    void func(int idx, vector<int>& candidates, vector<int>& temp, int target, int n,
              vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            if(candidates[i] <= target){
                temp.push_back(candidates[i]);
                func(i + 1, candidates, temp, target - candidates[i], n, ans);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        func(0, candidates, temp, target, candidates.size(), ans);

        return ans;
    }
};
