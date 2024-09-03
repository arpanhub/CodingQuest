class Solution {
public:
    string Gives_sum(string sum){
        int s = 0;
        int number = 0;
        for(int i = 0;i< sum.length();i++){
            number += sum[i] - '0';
        }
        return to_string(number);
        // while(number != 0){
        //     int r = number %10;
        //     s += r;
        //     number = number /10;
        // }
    }
    int getLucky(string s, int k) {
        string num ="";
        for(int i = 0;i < s.length();i++){
            num += to_string(s[i] - 'a' + 1);//36
        }
        string t = num;
        while(k!=0){
           t = (Gives_sum(t));
           k--;
        }
        return stoi(t);

    }
};