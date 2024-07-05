const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int calc(int index, int end, vector<int>& nums,vector<int>& dp) {
        if (index >= end)
            return 0;
        if(dp[index] != -1) return dp[index];
        dp[index] = max(nums[index] + calc(index + 2, end, nums,dp),calc(index + 1, end, nums,dp));
        // int m1 = nums[index] + calc(index + 2, end, nums);
        // int m2 = calc(index + 1, end, nums);
        return dp[index];
    }
    int rob(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp1(nums.size() + 1,-1);
        int ans1 = calc(0,n-1,nums,dp1);
        vector<int> dp2(nums.size() + 1,-1);
        int ans2 = calc(1,n,nums,dp2);
        return max(ans1,ans2);
    }
};