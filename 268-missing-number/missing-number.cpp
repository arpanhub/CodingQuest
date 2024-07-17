class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int array_xor = 0;
        int n_xor = 0;
        for(int i: nums){
            array_xor ^= i;
        }
        for(int i = 1;i <= nums.size();i++){
            n_xor ^= i;
        }
        return array_xor ^ n_xor;
    }
};