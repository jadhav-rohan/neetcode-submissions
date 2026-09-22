class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        prefix[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            if (prefix[i - 1] == 0)
                prefix[i] = nums[i];
            else
                prefix[i] = prefix[i - 1] * nums[i];
        }

        suffix[n - 1] = nums[n - 1];

        for(int i=nums.size() - 2; i>=0; i--){
            if (suffix[i + 1] == 0)
                suffix[i] = nums[i];
            else
                suffix[i] = suffix[i + 1] * nums[i];
        }

        for(int i=0; i<nums.size(); i++){
            ans = max(ans, prefix[i]);
        }
        for(int i=0; i<nums.size(); i++){
            ans = max(ans, suffix[i]);
        }

        return ans;
    }
};
