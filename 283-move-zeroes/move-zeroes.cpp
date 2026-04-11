class Solution {
public:
    void swap(int* a, int* b){
        int temp=*a;
        *a=*b;
        *b= temp;
    }
    void moveZeroes(vector<int>& nums) {
        int l=0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r]!=0){
                swap(&nums[l], &nums[r]);
                l++;
            }
        }
    }
};