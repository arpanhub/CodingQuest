class Solution {
public:
    int CountMoves(int idx_i,int idx_j,int row,int column,int &cnt,vector<vector<int>>& dp){
        if(idx_i == row-1 && idx_j == column -1){
            return 1;
        }
        if(idx_i == row || idx_j == column) return 0;
        if(dp[idx_i][idx_j]  != -1) return dp[idx_i][idx_j];
        dp[idx_i][idx_j] = CountMoves(idx_i+1,idx_j,row,column,cnt,dp) + CountMoves(idx_i,idx_j+1,row,column,cnt,dp);
        return dp[idx_i][idx_j];
    }
    int uniquePaths(int m, int n) {
        int cnt = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return CountMoves(0,0,m,n,cnt,dp);   
    //    return ways;
    // return cnt;
    }
};