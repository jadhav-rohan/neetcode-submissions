class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        priority_queue<int> minHeap;
        int n = arr.size();
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            if(minHeap.empty() == false){
                ans[i] = minHeap.top();
            }
            else{
                ans[i] = -1;
            }
            minHeap.push(arr[i]);
        }

        return ans;
    }
};