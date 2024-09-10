class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums[0];
        int b = nums[nums.size()-1];
        int res = a;
        while(res > 0){
            if(a % res == 0 && b % res == 0){
                break;
            }
            res--;
        }
        return res;
    }
};