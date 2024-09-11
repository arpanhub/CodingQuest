class Solution {
public:
    int minBitFlips(int start, int goal) {
        int k = 0;
        int count = 0;
     for(int i = 0;i < 32;i++){
        k = 1<<i;
        int a = start & k;
        int b = goal & k;
        if(a != b) count++;
     }
     return count++;
    }
};