class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int start = 0;
        long long int last = sqrt(c);
        while(last >= start)
        {
            if(start*start + last*last < c) start++;
            else if(start*start + last*last > c) last--;
            else  return true;
        }
        return false;
    }
};