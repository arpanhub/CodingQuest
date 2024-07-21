class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int Max_of_Mins_in_Row = INT_MIN;
        for(int row = 0;row < matrix.size();row++){
            int RowMin  = INT_MAX;
            for(int col =  0;col < matrix[0].size();col++){
                RowMin = min(RowMin,matrix[row][col]);
            }
            Max_of_Mins_in_Row = max(Max_of_Mins_in_Row,RowMin);
        }
        int Min_of_Maxs_in_Col = INT_MAX;
        for(int col = 0;col < matrix[0].size();col++){
            int Colmax  = INT_MIN;
            for(int row =  0;row < matrix.size();row++){
                Colmax = max(Colmax,matrix[row][col]);
            }
            Min_of_Maxs_in_Col = min(Min_of_Maxs_in_Col,Colmax);
        }
        if(Max_of_Mins_in_Row == Min_of_Maxs_in_Col) return {Min_of_Maxs_in_Col};
        else return {};
    }
};