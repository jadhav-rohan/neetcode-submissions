class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       vector<int> v;
       unordered_map<int, int> m;

       for(int i=0; i<nums.size(); i++){
          int curr = nums[i];
          int req = target - curr;
          if(m.find(req) != m.end()){
            v.push_back(m[req]);
            v.push_back(i);
          }
          m.insert({nums[i], i});
       }

       return v;

    }
};
