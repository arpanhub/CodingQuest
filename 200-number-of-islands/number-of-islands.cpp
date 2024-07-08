const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    void BFS(vector<vector<char>>& grid,int i,int j, vector<vector<char>>& visited){
        if(i >= grid.size() || j >= grid[0].size() || i<0||j<0|| grid[i][j] == '0') return;
        if(visited[i][j] == '0'){
            visited[i][j] = '1';
        }
        else{
            return;
        }
        BFS(grid,i,j+1,visited);
        BFS(grid,i+1,j,visited);
        BFS(grid,i-1,j,visited);
        BFS(grid,i,j-1,visited);
        return;        
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> visited(grid.size()+1,vector<char>(grid[0].size()+1,'0'));
        // visited[0][0] ='1';
        int cnt = 0;
        for(int row = 0;row < grid.size();row++){
            for(int col = 0;col < grid[0].size();col++){
                if(visited[row][col] == '0' && grid[row][col] == '1'){
                     cnt++;
                     BFS(grid,row,col,visited);
                }
            }
        }
        return cnt;

    }
};