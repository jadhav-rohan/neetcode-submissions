class Solution {
public:
    bool isPalindrome(int i, int idx, string s){
        while(idx <= i){
            if(s[i] != s[idx]){
                return false;
            }
            idx++;
            i--;
        }
        return true;
    }
    void func(string s, int idx, vector<string> &temp, vector<vector<string>> &ans){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i<s.size(); i++){
            if(isPalindrome(i, idx, s)){
                temp.push_back(s.substr(idx, i - idx + 1));
                func(s, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        func(s, 0, temp, ans);

        return ans;
    }
};
