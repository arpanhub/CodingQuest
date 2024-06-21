class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
       for(int n:nums){
        minheap.push(n);
        if(minheap.size() > k)  minheap.pop();
       }
       return minheap.top();
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();