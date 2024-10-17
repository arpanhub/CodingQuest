class NumArray {
public:
vector<long long> num;
    NumArray(vector<int>& nums) {
        // num.push_back(0);
        for(long long i:nums){
            num.push_back(i);
        }
        // for(int i:num){
        //     cout<<i<<" ";
        // }
    }
    
    int sumRange(int left, int right) {
        long long sum = 0;
        for(int i = left;i <= right;i++){
            sum += num[i];
            // cout<<"i="<<num[left]<<","<<sum<<" ";
        }
        cout<<endl;
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */