class Solution {
public:
    bool magic_matrix(int row,int column,vector<vector<int>>& grid){
        set<int> numbers;
        for (int i = row; i < row + 3; ++i) {
            for (int j = column; j < column + 3; ++j) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || !numbers.insert(num).second) {
                    return false;
                }
            }
        }
        int row_sum1 = grid[row][column] + grid[row][column+1] + grid[row][column+2];
        int row_sum2 = grid[row+1][column] + grid[row+1][column+1] + grid[row+1][column+2];
        int row_sum3 = grid[row+2][column] + grid[row+2][column+1] + grid[row+2][column+2];

        int col_sum1 = grid[row][column] + grid[row+1][column] + grid[row+2][column];
        int col_sum2 = grid[row][column+1] + grid[row+1][column+1] + grid[row+2][column+1];
        int col_sum3 = grid[row][column+2] + grid[row+1][column+2] + grid[row+2][column+2];

        int daig1 = grid[row][column] + grid[row+1][column+1] + grid[row+2][column+2];
        int daig2 = grid[row+2][column] + grid[row+1][column+1] + grid[row][column+2];
        if(row_sum1 == row_sum2 && row_sum2 == row_sum3 && row_sum3 == col_sum1 && col_sum1 == col_sum2 && col_sum2 == col_sum3 && col_sum3 == daig1 && daig1 == daig2 && daig2 == row_sum1){
            return true;
        }else{
            return false;
        }
        
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ctr = 0;
        if(grid.size() < 3 || grid[0].size() < 3){
            return 0;
        }
        for(int i = 0;i <= m - 3; i++){
            for(int j = 0;j <= n - 3;j++){
                if(magic_matrix(i,j,grid)){
                    ctr++;
                }
            }
        }
        return ctr;
    }
};