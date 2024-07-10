const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int cnt = 0;//1,0,1,0,-1
        for(int i = 0; i < n;i++){
            if(cnt < 0) cnt = 0;
            if(logs[i] == "../") cnt--;
            else if(logs[i] == "./") continue;
            else cnt++;
        }

        return (cnt < 0)?0:cnt;
    }
};