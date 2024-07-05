const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
    int CountMoves(int idx_i,int idx_j,int row,int column,vector<vector<int>> obstacleGrid,vector<vector<int>>& dp){
        if(idx_i == row-1 && idx_j == column -1 && obstacleGrid[idx_i][idx_j] != 1){
            return 1;
        }
        if(idx_i == row || idx_j == column || obstacleGrid[idx_i][idx_j] == 1) return 0;
        if(dp[idx_i][idx_j] != -1) return dp[idx_i][idx_j];
        dp[idx_i][idx_j] =  CountMoves(idx_i+1,idx_j,row,column,obstacleGrid,dp) + CountMoves(idx_i,idx_j+1,row,column,obstacleGrid,dp);
        return dp[idx_i][idx_j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int cnt = 0;
        vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, -1));
       return CountMoves(0,0,obstacleGrid.size(),obstacleGrid[0].size(),obstacleGrid,dp);
    }
};