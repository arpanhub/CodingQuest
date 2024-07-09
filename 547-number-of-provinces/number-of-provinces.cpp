class Solution {
public:
    void bfs(vector<int>& visited,vector<vector<int>>& adj,int i){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i:adj[node]){
                if(!visited[i]){
                visited[i] = 1;
                q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>> adj(n);
        for(int i = 0;i < n;i++){//adjacency list
            for(int j = 0;j < n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        // visited[0] = 1;
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                visited[i]=1;
                bfs(visited,adj,i);
                cnt++;
            }
        }
        return cnt;
    }
};