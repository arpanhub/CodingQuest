class Solution {
public:
    vector<int> getRow(int row){
        vector<int> tem;
        long long res = 1;
        tem.push_back(1);
        for(int i = 1;i < row;i++){
            res = res * (row-i);
            res = res/(i);
            tem.push_back(res);
        }
        return tem;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1;i <= numRows;i++){
            vector<int> temp = getRow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};