class Solution {
public:
    int solve(vector<int> &nums, int low, int high){
        int i = low, j = high;
        int pivot = nums[low];

        while(i <= j){
            while(i <= high && nums[i] <= pivot){
                i++;
            }
            while(j >= low && nums[j] > pivot){
                j--;
            }
            if(i < j) swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }

    void qs(vector<int> &nums, int low, int high){
        
        if(low < high){
            int partition = solve(nums, low, high);
            qs(nums, low, partition - 1);
            qs(nums, partition + 1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;

        qs(nums, low, high);

        return nums;
    }
};