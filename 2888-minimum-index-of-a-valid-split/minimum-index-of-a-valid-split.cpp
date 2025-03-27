class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i:nums){
            mp1[i]++;
        }
        int left_length = 0;
        int right_length = nums.size()-1;
        for(int i = 0;i < nums.size();i++){
            left_length = i + 1;//1
            right_length = nums.size() - i -1;//9
            int current = nums[i];
            mp2[current]++;
            mp1[current]--;
            if(mp2[current] >left_length/2 and mp1[current] > right_length/2){
                return i;
            }
        }
        return -1;
    }
};