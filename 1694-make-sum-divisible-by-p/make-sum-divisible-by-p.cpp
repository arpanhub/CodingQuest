class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for(int i:nums){
            sum +=i;
            sum = sum %p;
        }
        if(sum%p == 0) return 0;
        int target = sum%p;
        int cumulative_sum = 0;
        int length=nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i = 0;i < nums.size();i++){
            cumulative_sum =(cumulative_sum + nums[i])%p;  
            int prev = (cumulative_sum-target + p)%p;
            if(mp.find(prev)!=mp.end()){
                length = min(length,i-mp[prev]);
            }
            mp[cumulative_sum] = i;
        }
        return length==nums.size()?-1:length;
    }
};