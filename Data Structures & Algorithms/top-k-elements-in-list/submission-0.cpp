class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

       priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(auto itr = m.begin(); itr != m.end(); itr++){
            minHeap.push({itr->second, itr->first});

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        while(minHeap.size() > 0){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
       return ans;

    }
};
