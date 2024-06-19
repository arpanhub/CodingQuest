class Solution {
public:
    bool ispossible(vector<int> &bloomDay,int mid,int m,int k){
        int cnt = 0;
        int Number_of_bouquetes = 0;
        for(int i =0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }else{
                Number_of_bouquetes += (cnt/k);
                cnt = 0;
            }
        }
        Number_of_bouquetes += (cnt/k);
        return (Number_of_bouquetes >= m);

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = INT_MAX;
        int high = INT_MIN;
        int n = bloomDay.size();
        long long value = m * 1ll * k * 1ll;
        if(value > n) return -1;
        for(int &day:bloomDay){
            low = min(low,day);
            high = max(high,day);
        }
        while(low <= high){
            int mid = (high + low)/2;
            if(ispossible(bloomDay,mid,m,k)){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};