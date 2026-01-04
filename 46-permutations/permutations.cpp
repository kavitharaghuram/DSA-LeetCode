class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())return {{}};
        vector<int>tmp=vector<int>(nums.begin()+1, nums.end());
        vector<vector<int>>perms= permute(tmp);
        vector<vector<int>>res;
        for(const auto& p: perms){
            for(int i=0; i<=p.size(); i++){
                vector<int>pcopy=p;
                pcopy.insert(pcopy.begin()+i, nums[0]);
                res.push_back(pcopy);
            }
        }
        return res;
    }
};