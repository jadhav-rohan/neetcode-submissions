class Solution {
public:
    int find(vector<int> &nums, int start, int end, int target){
        int mid = (start + end) / 2;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int f = -1, s = -1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                f = find(nums, 0, i, target);
                s = find(nums, i+1, nums.size()-1, target);
                break;
            }
        }

        if(f != -1){
            return f;
        }else if( s != -1){
            return s;
        }
        return find(nums, 0, nums.size()-1, target);
    }
};
