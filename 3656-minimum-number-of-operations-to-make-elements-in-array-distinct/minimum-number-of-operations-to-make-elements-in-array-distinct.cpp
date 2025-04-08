class Solution {
public:
    bool distinct(vector<int>& nums,int idx){
        unordered_set<int> st;
        for(int i = idx;i < nums.size();i++){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
            }else{
                return false;
            }
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int N = nums.size()-1;
        int i = 0;
        int count = 0;
        while(!distinct(nums,i)){
            i +=3;
            count++;
            cout<<count<<" ";
        }
        return count;
    }
};