class Solution {
public:
    void func(vector<char> &s, int i, int n){
        if(i >= n / 2) return;

        swap(s[i], s[n-i-1]);
        func(s, i+1, n);
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        
        func(s, 0, n);
        
    }
};