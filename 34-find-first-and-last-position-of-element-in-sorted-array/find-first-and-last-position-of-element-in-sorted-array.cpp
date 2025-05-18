class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        int first = -1;
        int last = -1;
        while(left <= right){
            mid = (right + left)/2;
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                first = mid;
                right = mid - 1;
            }
        }
        left = 0;
        right = nums.size()-1;
        while(left <= right){
            mid = (right + left)/2;
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                last = mid;
                left = mid + 1;
                cout<<left<<" ";
            }
        }
        return {first,last};
        
    }
};