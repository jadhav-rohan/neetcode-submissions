class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        while (start <= end) {
            int mid = start + (end - start) / 2;

            int requiredDays = 1;
            int currentWeight = 0;

            for (int weight : weights) {
                if (currentWeight + weight > mid) {
                    requiredDays++;
                    currentWeight = 0;
                }

                currentWeight += weight;
            }

            if (requiredDays <= days) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};