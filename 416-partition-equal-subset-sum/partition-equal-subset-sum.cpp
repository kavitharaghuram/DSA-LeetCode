class Solution {
public:
    int helper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp ){
        if(target==0)return true;
        if(idx==0)return (nums[idx]==target);
        if(dp[idx][target]!=-1)return dp[idx][target];
        bool nottake=helper(idx-1, target, nums, dp);
        bool take=false;
        if(target>=nums[idx])take= helper(idx-1, target-nums[idx], nums, dp);
        return dp[idx][target]=take|| nottake;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int i=0; i<nums.size(); i++)totalSum+=nums[i];
        if(totalSum%2)return false;
        int target=totalSum/2;
        vector<vector<int>>dp(nums.size(), vector<int>(target+1, -1));
        return helper(nums.size()-1, target, nums, dp);
    }
};