class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        q.push({0,0});
        grid[0][0] = 1; 
        vector<int> dx ={-1,-1,-1,0,1,1,1,0};
        vector<int> dy ={-1,0,1,1,1,0,-1,-1};
        int count = 1;
        while(!q.empty()){
            size_t size = q.size();
            while(size--){
                auto it = q.front();q.pop();
                int row = it.first;
                int col = it.second;
                if(row == n-1 and col == m-1)return count;
                for(int i = 0;i < 8;i++){
                    int newr = row + dx[i];
                    int newy = col + dy[i];
                    if(newr >= 0 and newy >=0 and newr < n && newy < m and grid[newr][newy] == 0){
                       grid[newr][newy] = 1;
                       q.push({newr,newy});
                    }
                }
            }
            count++;
        }
        return -1;
    }
};