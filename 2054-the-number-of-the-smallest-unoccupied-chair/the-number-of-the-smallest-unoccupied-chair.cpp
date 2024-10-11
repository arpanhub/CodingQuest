class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for(int i = 0;i < times.size();i++){
            times[i].push_back(i);
        }
        sort(times.begin(),times.end());
        int n = times.size();
        vector<int> chairs(n,-1);
        for(int i = 0;i < n;i++){
            int arrival_time = times[i][0];
            int departure_time = times[i][1];
            int friend_number = times[i][2];
            chairs.push_back(departure_time);
            for(int j = 0;j<n;j++){
                if(chairs[j] <= arrival_time){
                    chairs[j] = departure_time;
                    if(friend_number == targetFriend){
                     return j;
                    }
                   break;     
                }
            }

        }
        return 0;
    }
};