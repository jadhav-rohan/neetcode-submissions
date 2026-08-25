class Solution {
public:
    int reqDays(vector<int> &weights, int val){
        int days = 1, currLoad = 0;

        for(int i=0; i<weights.size(); i++){
            if(currLoad + weights[i] > val){
                days++;
                currLoad = weights[i];
            }else{
                currLoad += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int requiredDays = reqDays(weights, mid);

            if (requiredDays <= days) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};