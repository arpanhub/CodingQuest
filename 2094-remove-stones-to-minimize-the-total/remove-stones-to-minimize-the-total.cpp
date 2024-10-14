class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
        int num = 0;
        int sum = 0;
        while(k--){
            num = pq.top();
            pq.pop();
            num =abs(num - floor(num/2));
            cout<<num<<" ";
            pq.push(num);
            // sum += num;
        }
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};