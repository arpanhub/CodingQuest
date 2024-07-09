class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        } 
        int maxTime=0;
        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            q.pop();

            maxTime = max(maxTime, time);
            int dx[4] = {1, 0, -1, 0};
            int dy[4] = {0, 1, 0, -1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    q.push({{newX, newY}, time+1});
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        } 
        return maxTime;        
    }
};