const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int calc(int index,vector<int>& nums,vector<int>& dp){
        if(index >= nums.size())
             return 0;
        if(dp[index] != -1) return dp[index];
        // int m1 = nums[index] + calc(index + 2,nums);
        // int m2 = calc(index + 1,nums);
        dp[index] = max(nums[index] + calc(index + 2,nums,dp),calc(index + 1,nums,dp));
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int index = 0;
        vector<int> dp(nums.size() +1,-1);
        return calc(0,nums,dp);
    }
};