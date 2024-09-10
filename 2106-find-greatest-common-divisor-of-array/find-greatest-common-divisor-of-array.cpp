class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] < min) min = nums[i];
            if(nums[i] > max) max = nums[i];
        }
        int a =min;
        int b = max;
        int res = min;
        while(res > 0){
            if(a % res == 0 && b % res == 0){
                break;
            }
            res--;
        }
        return res;
    }
};