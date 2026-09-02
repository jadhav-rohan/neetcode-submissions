class Solution {
   public:
    int countSeniors(vector<string>& details) {
        int n = details.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            string s = details[i];
            string sub = s.substr(s.size() - 4, 2);

            int age = stoi(sub);
            if (age > 60) {
                ans++;
            }
        }

        return ans;
    }
};