class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        unordered_set<int> s;
        for(int i = 0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int curr = 1;
        int longest = 1;
        for(auto itr = s.begin(); itr != s.end(); itr++){
            int val = *itr;
            if(s.find(val - 1) != s.end()){
                continue;
            } 
            else if(s.find(val - 1) == s.end()){
                curr = 1;
                val = *itr;
                while(s.find(val + 1) != s.end()){
                    curr++;
                    val = val + 1;
                }
            }
            else{
                curr = 1;
            }
            longest = max(longest, curr);
        }

        return longest;
    }
};
