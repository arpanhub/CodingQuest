class Solution {
public:
    int give(int sum){
        int sums = 0;
        while(sum != 0){
            int r = sum % 10;
            sums += r;
            sum =sum /10;
        }
        return sums;
    }
    int addDigits(int num) {
        int sum = 0;
        while(num != 0){
            int r = num % 10;
            sum += r;
            num =num /10;
        }
        while(sum >9){
           sum =  give(sum);
        }
        return sum;
    }
};