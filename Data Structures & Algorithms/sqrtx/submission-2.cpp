class Solution {
   public:
    int mySqrt(int x) {
        int n = x;
        int start = 1, end = n;
        if(x == 0) return 0;
        long long ans = INT_MIN;
        while(start <= end) {
            long long mid = start + (end - start) / 2;
            long long square = mid * mid;
            if (square > n) {
                end = mid - 1;
            } else {
                ans = max(ans, mid);
                start = mid + 1;
            }
        }
        return ans;
    }
};