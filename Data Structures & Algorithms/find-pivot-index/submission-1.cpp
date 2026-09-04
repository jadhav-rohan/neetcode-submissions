class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prefix[i] = 0;
                continue;
            }
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                suffix[i] = 0;
                continue;
            }
            suffix[i] = suffix[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            cout << prefix[i] << " ";
        }
        cout << endl;
        for (int j = 0; j < n; j++) {
            cout << suffix[j] << " ";
        }

        for (int i = 0; i < n; i++) {
            if (prefix[i] == suffix[i]) {
                return i;
            }
        }
        
        return -1;
    }
};