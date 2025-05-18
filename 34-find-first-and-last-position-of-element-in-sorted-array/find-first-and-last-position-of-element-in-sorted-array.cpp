class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int first = -1;
        int last = -1;
        while(low <= high){
            mid = (high + low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                first = mid;
                high = mid - 1;
            }
        }
        low = 0;
        high = nums.size()-1;
        while(low <= high){
            mid = (high + low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                last = mid;
                low = mid + 1;
                cout<<low<<" ";
            }
        }
        return {first,last};
        
    }
};