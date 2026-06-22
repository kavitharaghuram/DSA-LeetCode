class Solution {
public:
    int subsetsum(vector<int>& nums){
        int n= nums.size();
        if(n==1)return nums[0];
        int prev=nums[0];
        int prev2=0;
        for(int i=1; i<n; i++){
            int take = nums[i];
            if(i>=2)take+=prev2;
            int nottake= prev;
            int curri=max(take, nottake);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int>arr1, arr2;
        if(nums.size()==1)return nums[0];
        for(int i=0; i<nums.size(); i++){
            if(i!=0)arr1.push_back(nums[i]);
            if(i!=nums.size()-1)arr2.push_back(nums[i]);
        }
        return max(subsetsum(arr1), subsetsum(arr2));
    }
};