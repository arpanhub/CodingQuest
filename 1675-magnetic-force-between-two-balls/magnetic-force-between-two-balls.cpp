class Solution {
public:
    bool Minimum_Magnetic_force(vector<int> position,int mid ,int m){
        int balls = 1;
        int pos = position[0];
        for(int i = 1;i<position.size();i++){
            if(position[i] - pos >= mid){
                balls++;
                pos = position[i];
            }
            if(balls == m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low = 1;
        int high = position[n-1];
        int MMF=0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(Minimum_Magnetic_force(position,mid,m)){
                MMF = mid;
                low = mid  + 1;
            }else{
                high = mid -1 ;
            }
        }
        return MMF;
    }
};