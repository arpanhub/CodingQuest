class Solution {
public:
    void permute(vector<int>& nums,unordered_map<int,int>& mp,vector<vector<int>>& ans,vector<int> ds){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(mp[nums[i]] == 0){
                ds.push_back(nums[i]);
                mp[nums[i]] = 1;
                permute(nums,mp,ans,ds);
                ds.pop_back();
                mp[nums[i]] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        vector<int> ds;
        permute(nums,mp,ans,ds);
        return ans;
    }
};