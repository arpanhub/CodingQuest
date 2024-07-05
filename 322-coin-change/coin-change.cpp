class Solution {
public:
    int sum(vector<int>& coins,int amount,int index, vector<vector<int>>& dp){
        if(index == coins.size()){
            if(amount == 0){
                return 0;
            }else{
                return 1e9;
            }
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int pick = 1e9;
        if(coins[index] <= amount){
            pick = 1+ sum(coins,amount - coins[index],index,dp);
        }
        int notpick = 0 + sum(coins,amount,index+1,dp);
        dp[index][amount] = min(pick,notpick);
        return dp[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount + 1,-1));
        int ans = sum(coins,amount,0,dp);
        if( ans == 1e9){
            return -1;
        }else{
            return ans;
        }
    }
};