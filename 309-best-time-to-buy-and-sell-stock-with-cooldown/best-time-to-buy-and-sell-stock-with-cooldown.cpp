class Solution {
public:
    int price(vector<int>& prices,int index,int buy,int profit,vector<vector<int>>& dp){
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy == 1)
        {
         profit = max( -prices[index] + price(prices,index + 1,0,profit,dp),0 + price(prices,index + 1,1,profit,dp));
        }else{
         profit = max( prices[index] + price(prices,index + 2,1,profit,dp),0 + price(prices,index + 1,0,profit,dp));
        }
        return dp[index][buy] =profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return price(prices,0,1,0,dp);
    }
};