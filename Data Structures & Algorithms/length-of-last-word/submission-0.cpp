class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans = 0;

        int j = n - 1;
        int space = 0;
        while(j >= 0){
            if(s[j] != ' '){
                ans++;
                j--;
            }
            if(ans == 0 && s[j] == ' '){
                j--;
                // continue;
            }
            if(ans != 0 && s[j] == ' '){
                break;
            }
        }

        return ans;
    }
};