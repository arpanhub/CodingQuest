class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates,int target,int start,vector<int>& path){
        if(target == 0){
            result.push_back(path);
        }
        if(target < 0){
            return;
        }
        for(int i = start; i < candidates.size();i++){
            if( i > start && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            backtracking(candidates,target-candidates[i],i+1,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        backtracking(candidates,target,0,path);
        return result;
    }
};
