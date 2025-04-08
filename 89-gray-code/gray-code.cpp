class Solution {
public:
    vector<int> grayCode(int n) {
        // int N = pow(n);
        vector<int>v;
        for(int i=0;i<(1<<n);i++){
            int a=i^(i>>1);
            v.push_back(a);
        }
        return v;
    }
};