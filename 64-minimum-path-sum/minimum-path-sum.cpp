const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int MinSum(vector<vector<int>>& grid,int i, int j,vector<vector<int>>& dp){
        
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return grid[i][j];
        }
        if(i >= grid.size() || j >= grid[0].size()){
            return 1e8;
        }
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = min(grid[i][j] +MinSum(grid,i+1,j,dp),grid[i][j] + MinSum(grid,i,j+1,dp));
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return MinSum(grid,0,0,dp);
    }
};