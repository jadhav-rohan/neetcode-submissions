class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        int size = nums.size();

        set<int> s;
        set<vector<int>> ansSet;
        for(int i=0; i<size; i++){
            s.clear();

            for(int j=i+1; j<size; j++){
                int sum = nums[i] + nums[j];
                sum *= -1;
                if(s.find(sum) != s.end()){
                    vector<int> temp = {nums[i], nums[j], sum};
                    sort(temp.begin(), temp.end());
                    ansSet.insert(temp);
                }
                s.insert(nums[j]);
            }
        }

        for(auto itr = ansSet.begin(); itr!= ansSet.end(); itr++){
            ans.push_back(*itr);
        }
        
        return ans;
    }
};
