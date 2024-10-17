class Solution {
public:
    int maximumSwap(int num) {
        string  s = to_string(num);
        int n = s.size();
        vector<int> maxintger(n);
        maxintger[n-1] = n-1;
        for(int i = n-2;i>=0;i--){
            int maxInt = s[maxintger[i+1]];//8
            int maxIdx =maxintger[i+1];//4
            maxintger[i] = (s[i]>maxInt)?i:maxIdx;
        }
        for(int i = 0;i<n;i++){
            if(s[maxintger[i]] > s[i]){
                swap(s[i],s[maxintger[i]]);
                stoi(s);
                return stoi(s);
            }
        }
        return num;
    }
};