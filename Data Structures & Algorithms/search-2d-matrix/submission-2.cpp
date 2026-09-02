class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            vector<int> temp = matrix[i];
            int n = temp.size();

            int start = 0, end = n - 1;

            if(target <= temp[end]){
                while(start <= end){
                    int mid = (start + end) / 2;
                    if(temp[mid] == target){
                        return true;
                    }
                    if(temp[mid] < target){
                        start = mid + 1;
                    }
                    else{
                        end = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};
