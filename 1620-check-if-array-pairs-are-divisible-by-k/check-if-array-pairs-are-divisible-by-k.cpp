class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k,0);
        for(int i:arr){
            int rem = ((i%k)+k)%k;
            mp[rem]++;
        }
        if(mp[0]%2!=0)return false;
        for(int i = 1;i < k;i++){
            int findrem = k-i;
            if(mp[findrem] != mp[i]){
                return false;
            }
        }
        return true;
    }
};