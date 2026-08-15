class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int targetFreq = nums.size() / 2;
        int ans = INT_MIN;
        int f;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        //1, 3
        //5, 4
        for(auto itr = m.begin(); itr != m.end(); itr++){
            if(itr->second >= targetFreq){
                if(itr-> second > ans){
                    ans = max(ans, itr->second);
                    f = itr->first;
                }
            }
        }

        return f;
    }
};