class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(string str:arr){
            mp[str]++;
        }
        int ctr = 0;
        for(string str2:arr){
            // cout<<it.first<<"-"<<it.second<<"   ";
            if(mp[str2] == 1){
                ctr++;
                if(ctr == k) return str2;
            }
        }
        return "";
    }
};