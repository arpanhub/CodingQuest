class Solution {
public:
    bool ispalindrom(const string& s, int i, int j) {
       if(i >= j) return true;
       if(s[i] != s[j]) return false;
       return ispalindrom(s,i+1,j-1);
    }
    string LPS(string s){
        int maxLength = 0;
        int start_point = 0;
        for(int i = 0;i < s.size();i++){
            for(int j = i;j < s.size();j++){
                if(ispalindrom(s,i,j)){
                   if ((j-i+1) > maxLength) {
                        maxLength = (j-i+1);
                        start_point = i;
                    }
                }
            }
        }
        if(maxLength==0)return "";
        else return s.substr(start_point,maxLength);
    }
    string longestPalindrome(string s) {
        return LPS(s);
    }
};
