class Solution {
public:
    long long solve(string str,int limit,string suffix){
        if(suffix.size()>str.size())return 0;
        string remaining_str = str.substr(0,str.size()-suffix.size());
        string fixed_str_part = str.substr(remaining_str.length(),str.size());
        long long count = 0;
        int remaining_str_size = remaining_str.size();
        for(int i = 0;i < remaining_str_size;i++){
           int digit = remaining_str[i]-'0';
           if(digit <= limit){
                count += digit*pow(limit+1,remaining_str_size-i-1);
           }else{
                count += (limit+1)*pow(limit+1,remaining_str_size-i-1);
                return count;
           }
        }
        if(fixed_str_part >= suffix){
            count += 1;
        }
        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return solve(to_string(finish),limit,s) - solve(to_string(start-1),limit,s);
        // return 1;
    }
};