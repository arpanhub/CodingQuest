class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(),worker.end(),greater<int>());
        priority_queue<pair<int,int>> pq;
        int n = difficulty.size();
        for(int i = 0;i < n;i++){
            pq.push({profit[i],difficulty[i]});
        }
        int n2 = worker.size();
        int i = 0;
        int maxProfit = 0;
        while(i < n2 && !pq.empty()){
            if(worker[i] >= pq.top().second){
                maxProfit += pq.top().first;
                i++;
            }else{
               pq.pop();
            }
        }
        return maxProfit;
    }
};