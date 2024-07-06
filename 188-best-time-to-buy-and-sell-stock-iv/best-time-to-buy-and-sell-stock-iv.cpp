
class Solution {
public:
    int price(vector<int>& prices,int index,int buy,int profit,vector<vector<vector<int>>>& dp,int k){
        if(index >= prices.size() || k == 0){
            return 0;
        }
        if(dp[index][buy][k] != -1) return dp[index][buy][k];
        if(buy == 1)
        {
         profit = max( -prices[index] + price(prices,index + 1,0,profit,dp,k),0 + price(prices,index + 1,1,profit,dp,k));
        }else{
         profit = max( prices[index] + price(prices,index + 1,1,profit,dp,k-1),0 + price(prices,index + 1,0,profit,dp,k));
        }
        return dp[index][buy][k] =profit;
    }
    int maxProfit(int k, vector<int>& prices) {

        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return price(prices,0,1,0,dp,k);
    }
};