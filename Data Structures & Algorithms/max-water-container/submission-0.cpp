class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = INT_MIN;

        int n = heights.size();

        int i=0, j=n-1;

        while(j > i){
            int curr = (j - i) * min(heights[i], heights[j]);
            if(heights[i] < heights[j]){
                i++;
            }else{
                j--;
            }
            ans = max(curr, ans);
        }

        return ans;
        
    }
};
