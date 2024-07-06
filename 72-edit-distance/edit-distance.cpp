const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minDist(string s1,string s2,int i,int j,vector<vector<int>>& dp){
        if(i == s1.length()){
            return s2.length()-j;
        }
        if(j == s2.length()){
            return s1.length()-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]) return dp[i][j] = minDist(s1,s2,i + 1,j + 1,dp);
        return dp[i][j] = min({(1+minDist(s1,s2,i + 1,j + 1,dp)),(1+minDist(s1,s2,i + 1,j,dp)),(1 +minDist(s1,s2,i,j + 1,dp))});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
       return  minDist(word1,word2,0,0,dp);
    }
};