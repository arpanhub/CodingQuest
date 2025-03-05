class Solution {
public:
    const int MOD = 1e9 + 7; // 1000000007

    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int ans = 0;
        long long sum = 0;
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            long long num = (1LL * (1LL*nums[i] * nums[i])%MOD) % MOD;
 // Compute square with long long
            ans = (nums[i+1] + 2LL * ans) % MOD;       // Apply mod to ans update
            sum = (sum + (1LL * (ans * num)%MOD) % MOD) % MOD; // Update sum with mod
        }
        
        for (int v : nums) {
            sum = (sum + (1LL *((1LL*v * v)%MOD * v)%MOD) % MOD) % MOD; // Add cube of each v with mod
        }
        
        return sum % MOD;
    }
};
