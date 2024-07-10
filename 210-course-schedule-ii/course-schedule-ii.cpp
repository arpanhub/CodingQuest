class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> res;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int i:adj[node]){
                INdegree[i]--;
                if(INdegree[i] == 0){
                    q.push(i);
                }
            }
        }
        if(res.size() != numCourses) return {};
        else return res;
    }   
};