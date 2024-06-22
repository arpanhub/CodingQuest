class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int oddCount = 0;
        int res = 0;
        mp[0] = 1;
        for(int i:nums){
            if(i % 2 != 0)  oddCount++;
            if(mp.find(oddCount - k) != mp.end()){
                res += mp[oddCount - k];
            }
            mp[oddCount]++;
        }
        return res;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();