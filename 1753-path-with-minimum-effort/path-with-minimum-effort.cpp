class Solution {
public:
    bool isSafe(vector<vector<int>>& heights, int i, int j) {
        return i >= 0 && i < heights.size() && j >= 0 && j < heights[0].size();
    }

    int minimumEffortPath(std::vector<std::vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
       vector<int> dx = {-1, 1, 0, 0};
       vector<int> dy = {0, 0, -1, 1};
        
        
       priority_queue<vector<int>,vector<std::vector<int>>,greater<>> pq;
        pq.push({0, 0, 0});  // starting point, effort is 0
        
        // Matrix to track the minimum effort to reach each cell
       vector<vector<int>> effort(n,vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int currEffort = cell[0];
            int row = cell[1];
            int col = cell[2];
            
            if (row == n - 1 && col == m - 1) {
                return currEffort;
            }
            
            for (int i = 0; i < 4; i++) {
                int newR = row + dx[i];
                int newC = col + dy[i];
                
                if (isSafe(heights, newR, newC)) {
                    int newEffort =max(currEffort,abs(heights[row][col] - heights[newR][newC]));
                    if (newEffort < effort[newR][newC]) {
                        effort[newR][newC] = newEffort;
                        pq.push({newEffort, newR, newC});
                    }
                }
            }
        }
        
        return 0;  
    }
};
