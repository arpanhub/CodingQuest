class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i:nums){
            pq.push(i);
        }
        // cout<<pq.top();
        long long sum = 0;
        int num;
        long long num1;
        while(k--){
            num = pq.top();
            pq.pop();
            sum += num;
            // num = (num /3.0);
            // // cout<<num<<endl;
            // num1 = ceil(num);
            // cout<<num1<<" ";
            pq.push((num+2)/3);
            // cout<<pq.top()<<" ";
        }
        return sum;
    }
};