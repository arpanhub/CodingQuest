class Solution {
public:
    void solve(vector<int>& candidates,int target, vector<vector<int>>& res,vector<int> path,int idx){
        if(idx == candidates.size()){
            if(target == 0){
                res.push_back(path);
            }
            return;
        }
        if(target >= candidates[idx]){
            path.push_back(candidates[idx]);
            solve(candidates,target-candidates[idx],res,path,idx);
            path.pop_back();
        }
        solve(candidates,target,res,path,idx+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        solve(candidates,target,res,path,0);
        return res;
    }
};