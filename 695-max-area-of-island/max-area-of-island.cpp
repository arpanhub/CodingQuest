const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int BFS(vector<vector<int>>& grid,int i,int j, vector<vector<int>>& visited,int& area){
        if(i >= grid.size() || j >= grid[0].size() || i<0||j<0|| grid[i][j] == 0) return 0;
        if(visited[i][j] == 0){
            visited[i][j] = 1;
            ++area;
        }
        else{
            return 0;
        }
        BFS(grid,i,j+1,visited,area);
        BFS(grid,i+1,j,visited,area);
        BFS(grid,i-1,j,visited,area);
        BFS(grid,i,j-1,visited,area);
        return area;        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int area=0;
        for(int row = 0;row < grid.size();row++){
            for(int col = 0;col < grid[0].size();col++){
                if(visited[row][col] == 0 && grid[row][col] == 1){
                    int a = 0;
                     area = max(area,BFS(grid,row,col,visited,a));
                }
            }
        }
        return area;

    }
};