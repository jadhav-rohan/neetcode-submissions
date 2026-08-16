class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int longest = INT_MIN;
        
        unordered_set<int> s;

        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }

        for(auto itr = s.begin(); itr != s.end(); itr++){
            int val = *itr;
            int curr = 1;
            if(s.find(val - 1) == s.end()){
                while(s.find(val+1) != s.end()){
                    curr++;
                    val = val + 1;
                }
            }else{
                continue;
            }
            longest = max(curr, longest);
        }

        return longest;
    }
};
