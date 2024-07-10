class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<int> visited(numCourses,0);
           vector<vector<int>> adj(numCourses);
           vector<int> INdegree(numCourses,0);
        for(int i = 0;i < prerequisites.size();i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            adj[u].push_back(v);
            INdegree[v]++;
        }
        queue<int> q;
        for(int i = 0;i < numCourses;i++){
            if(INdegree[i] == 0){
                q.push(i);
            }
        }
        int c = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            c++;
            for(int i:adj[node]){
                INdegree[i]--;
                if(INdegree[i] == 0){
                    q.push(i);
                }
            }
        }
        return c == numCourses;
    }
};