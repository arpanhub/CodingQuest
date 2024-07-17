class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = 0;
        int countONes = 0;
        int res = 0;
        for(int i = 0;i < 32;i++){
            temp = 1 << i;
            for(int num:nums){
                if((num & temp) != 0){
                    countONes++;
                }
            }
            if(countONes % 3 == 1) res |= temp;
            countONes = 0;
        }
        return res;
    }
};