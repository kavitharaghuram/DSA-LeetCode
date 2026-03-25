class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1idx;
        for(int i=0; i<nums1.size(); i++){
            nums1idx[nums1[i]]=i;
        }
        vector<int> res(nums1.size(), -1);
        for(int i=0; i<nums2.size(); i++){
            if(!nums1idx.count(nums2[i])){
                continue;
            }
            for(int j=i+1; j<nums2.size(); j++){
                if(nums2[j]>nums2[i]){
                    int idx=nums1idx[nums2[i]];
                    res[idx]=nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};