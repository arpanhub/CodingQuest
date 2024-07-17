class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = matrix.size() * matrix[0].size() -1;
        int col = 0;
        int row  = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            row = mid / matrix[0].size();
            col = mid % matrix[0].size();
            if(matrix[row][col] == target){
                return true;
            }
            else{
            if(matrix[row][col] > target){
                    end = mid - 1;
                }else{
                    start = mid + 1;
            }
        }
    }
    return false;
    }
};