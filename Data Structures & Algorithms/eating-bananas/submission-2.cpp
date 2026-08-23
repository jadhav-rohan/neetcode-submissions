class Solution {
public:
    int findHrs(vector<int> &piles, int val){
        float ans = 0;

        for(int i=0; i<piles.size(); i++){
            ans += ceil(double(piles[i])/double(val));
        }
        return ans;
    
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int start = 1, end = piles[n-1];    
        int ans = INT_MAX;
        while(start <= end){
            int mid = (start + end) / 2;

            int curr = findHrs(piles, mid);
            if(curr > h){
                start = mid + 1;
            }
            else{
                ans = min(ans, mid);
                end = mid - 1;
                
            }
        }

        return ans;
    }
};
