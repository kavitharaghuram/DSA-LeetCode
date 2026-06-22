class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size());
        if(nums.size()==1)return nums[0];
        dp[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            int take= nums[i];
            if(i>1)take+=dp[i-2];
            int nontake= dp[i-1];
            dp[i]=max(take, nontake);
        }
        return dp[nums.size()-1];
    }
};