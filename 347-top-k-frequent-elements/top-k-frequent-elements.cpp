class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i:nums) mp[i]++;
        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};



const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();