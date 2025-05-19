class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Sum = 0;
        int maxi = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            Sum += nums[i];
            maxi = max(Sum,maxi);
            if(Sum < 0) Sum = 0;
        }
        return maxi;
    }
};