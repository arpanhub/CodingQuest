const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n,0);
        for(auto & vec: roads){
            int u = vec[0];
            int v = vec[1];
            degrees[u]++;
            degrees[v]++;
        }
        sort(degrees.begin(),degrees.end());
        long long value = 1;
        long long sum = 0;
        for(int i = 0;i < n;i++){
           sum += value * degrees[i];
           value++;
        }
        return sum;
    }
};