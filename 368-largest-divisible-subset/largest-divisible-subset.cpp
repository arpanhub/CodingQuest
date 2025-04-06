class Solution {
public:
    vector<vector<vector<int>>> dp;  
    vector<int> solve(vector<int> &nums,int previdx,int curridx){
        if(curridx == nums.size()){
            return {};
        }
        if(dp[previdx+1][curridx].size() > 0){
            return dp[previdx+1][curridx];
        }
        vector<int> nottake = solve(nums,previdx,curridx+1);
        vector<int> take;
        if(previdx == -1 || nums[curridx] % nums[previdx] == 0){
            take = solve(nums,curridx,curridx+1);
            take.push_back(nums[curridx]);
        }
        dp[previdx+1][curridx] =  (nottake.size()>take.size())?nottake:take;
        return dp[previdx+1][curridx];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        dp = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(N, vector<int>()));

        sort(nums.begin(), nums.end());
        return solve(nums,-1,0);
    }
};