class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int a = coordinate1[0]-'0' + coordinate1[1];
        int b = coordinate2[0]-'0'+ coordinate2[1];
        return !((a+b)%2);
        
    }
};