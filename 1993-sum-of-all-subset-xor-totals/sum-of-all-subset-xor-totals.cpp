class Solution {
public:
    void solve(vector<int>& nums,int index,int curXor,int& txor){
        if(index == nums.size()){
            txor += curXor;
            return;
        }
        solve(nums,index+1,nums[index]^curXor,txor);
        solve(nums,index+1,curXor,txor);
    }
    int subsetXORSum(vector<int>& nums) {
        int txor = 0;
        solve(nums,0,0,txor);
        return txor;
    }
};