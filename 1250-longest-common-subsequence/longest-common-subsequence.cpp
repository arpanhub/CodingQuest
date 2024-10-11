class Solution {
public:
    int longestLength(string& text1,string& text2,int m,int n,vector<vector<int>>& dp){
        if( m< 0 || n < 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];

          if (text1[m] == text2[n]) {
            dp[m][n] = 1 + longestLength(text1, text2, m - 1, n - 1, dp);
        } else {
           
            int leftmax = longestLength(text1, text2, m - 1, n, dp);
            int rightmax = longestLength(text1, text2, m, n - 1, dp);
            dp[m][n] = max(leftmax, rightmax);
        }

        return dp[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.length() <=0 || text2.length() <= 0) return 0;
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return longestLength(text1,text2,text1.length()-1,text2.length()-1,dp);
    }
};