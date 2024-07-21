class Solution {
public:     
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int Row_Length = rowSum.size();
        int Col_Length = colSum.size();
        vector<vector<int>> matrix(Row_Length, vector<int>(Col_Length));
        for(int col = 0;col < Col_Length;col++){
            for(int row = 0; row < Row_Length;row++){
                int mini = min(rowSum[row],colSum[col]);
                rowSum[row] = rowSum[row] - mini;
                colSum[col] = colSum[col] - mini;
                matrix[row][col] = mini;
            }
        } 
        return matrix;  
    }
};