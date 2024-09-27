class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        for(int i = 1;i < numRows;i++){
            vector<int> sub;
            vector<int> lastarray = triangle.back();
            for(int j = 0;j< i+1;j++){
                if(j == 0) sub.push_back(1);
                if(i == j) sub.push_back(1);
                else if(i>0 && j>0){
                    sub.push_back(lastarray[j-1]+lastarray[j]);
                }
            }
            triangle.push_back(sub);
        }
        return triangle;
    }
};