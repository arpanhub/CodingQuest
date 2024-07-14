class Solution {
public:
    vector<vector<string>> res;
    int N;
    unordered_set<int> col_set;
    unordered_set<int> diag_set;
    unordered_set<int> antidiag_set;
    void solve(vector<string>& board,int row){
        if(row >= N){
            res.push_back(board);
            return;
        }
        for(int col = 0;col < N;col++){
            int col_const = col;
            int diagonal_const = row + col;
            int anit_diagonal_const = row - col;
            if(col_set.find(col) != col_set.end() || diag_set.find(diagonal_const) != diag_set.end() || antidiag_set.find(anit_diagonal_const) != antidiag_set.end()){
                continue;
            }
            col_set.insert(col_const);
            diag_set.insert(diagonal_const);
            antidiag_set.insert(anit_diagonal_const);
            board[row][col] = 'Q';
            solve(board,row + 1);
            col_set.erase(col_const);
            diag_set.erase(diagonal_const);
            antidiag_set.erase(anit_diagonal_const);
            board[row][col] = '.';

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<string> board(n, string(n,'.'));//n - 3;{"...","...","..."}
        solve(board,0);
        return res;
    }
};