class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        int i = 0, j = prices.size() - 1;

        int prev_min = prices[0];

        for(int i=1; i<prices.size(); i++){
            if(prev_min > prices[i]){
                prev_min = prices[i];
            }
            if(prices[i] - prev_min > ans){
                ans = prices[i] - prev_min;
            }
        }

        return ans;
    }
};
