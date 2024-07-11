class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
     vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto& edge:edges){//adjancecny list and indegree
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        vector<int> res;
        if(n==1) return {0};
        queue<int> q;
        for(int i = 0;i < n;i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        while(n > 2){
            int size = q.size();
            n = n - size;
            while(size--){
                int node = q.front();
                q.pop();
                for(int i:adj[node]){
                    indegree[i]--;
                    if(indegree[i] == 1){
                        q.push(i);
                    }
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
