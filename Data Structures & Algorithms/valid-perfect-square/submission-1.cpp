class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 1, end = num;

        while(start <= end){
            long long mid = (start + end) / 2;
            long long val = mid * mid;
            // cout<<val<<" ";
            if(val == num){
                return true;
            }
            if(val > num){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        return false;
    }
};