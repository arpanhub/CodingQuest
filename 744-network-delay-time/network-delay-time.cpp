class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(vector<int> v:times){
            int from = v[0];
            int to = v[1];
            int time_taken = v[2];
            adj[from].push_back({to,time_taken});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // Min-heap (time, node)
        vector<int> minTime(n+1,1e9);
        minTime[k] = 0;
        q.push({0,k});
        while(!q.empty()){
            // int size = q.size();
            // while(size--){
                auto it = q.top();q.pop();
                int node = it.second;
                int time = it.first;
                if (time > minTime[node]) continue;
                for(auto it:adj[node]){
                    int curr_node = it.first;
                    int curr_node_time = it.second;
                    int newTime = time + curr_node_time;
                    if (newTime < minTime[curr_node]) {
                        minTime[curr_node] = newTime;
                        q.push({newTime, curr_node});
                    }
                }
        }
        int maxi = 0;
        for(int m = 1;m <= n;m++){
            // cout<<minTime[m]<<" ";
            if(minTime[m]==1e9) return -1;
                maxi = max(maxi,minTime[m]);
            }
        return maxi;
    }
};