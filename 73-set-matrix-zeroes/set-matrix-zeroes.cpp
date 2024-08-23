class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rows(n,0);
        vector<int> col(m,0);
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    rows[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(rows[i] >0 || col[j] > 0){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};