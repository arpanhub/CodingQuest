const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
// without DP

/* class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n== 1){
            return 1;
        }
       int xways1step =  climbStairs(n-1);
       int yways2step =  climbStairs(n-2);
       return xways1step + yways2step;
    }
}; */
// with DP

class Solution {
public:
    int DPsolution(vector<int>& dp,int n){
        if(n==0 || n== 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = DPsolution(dp,n-1) + DPsolution(dp,n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return DPsolution(dp,n);
    }
};