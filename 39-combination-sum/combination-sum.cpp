class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<int>& arr, vector<vector<int>>&ans, int idx){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(arr);
            }
            return;
        }
        if(candidates[idx]<=target){
            arr.push_back(candidates[idx]);
            helper(candidates, target-candidates[idx], arr, ans, idx);
            arr.pop_back();
        }
        helper(candidates, target, arr, ans, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>arr;
        helper(candidates, target, arr, ans, 0);
        return ans;
    }
};