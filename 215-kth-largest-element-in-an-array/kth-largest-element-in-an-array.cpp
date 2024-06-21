class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxheap;
        for(int n:nums){
            maxheap.push(n);
        }
        for(int i = 1;i < k;i++){
            maxheap.pop();
        }
      return maxheap.top();
    }
};