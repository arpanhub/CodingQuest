class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map <int,int> mp;
        // mp[0] = -1;
        int count = 0;
        for(int i = 0;i < nums.size();i++)
        {
            sum += nums[i];
            if(sum == k) count++;//1,
            if(mp.find(sum-k) != mp.end()){
                count = mp[sum-k] + count;
            }
            if(mp.find(sum) != mp.end()){
                mp[sum]++;
            }
            else{
                mp[sum] = 1;
            }
        }
        return count;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();