class Solution {
public:
    int func(vector<int> &weights, int capacity){
        int days = 1, currLoad = 0;

        for(int i=0; i<weights.size(); i++){
            if(currLoad + weights[i] > capacity){
                // 2
                days++; // 2, 3, 4
                currLoad = weights[i]; //5, 4, 4
            }
            else{
                currLoad += weights[i]; // 1, 4,
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // 2,4,6,1,3,10

        //6

        //[2,4]
        //6
        //1,3
        //csnnot ship

        //least 10
        //sum of weights
        //26

        //10 -> 26

        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        int ans = 0;

        for(int i = start; i<= end; i++){
            int req = func(weights, i);
            //(weights, 5)

            if(req <= days){
                return i;
            }
        }

        return -1;
    }
};