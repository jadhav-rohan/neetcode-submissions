class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, count = 0;

        map<char, int> m;

        int left = 0, right = 0;

        while(right < s.size()){
            if(m.find(s[right]) != m.end()){
                if(m[s[right]] >= left){
                    left = m[s[right]] + 1;
                }
            }
            count = right - left + 1;
            ans = max(count, ans);
            m[s[right]] = right;
            right++;
        }

        return ans;
    }
};
