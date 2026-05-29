class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minPrice=INT_MAX;
        for(int p: prices){
            if(p<minPrice){
                minPrice=p;
            }
            int profit= p- minPrice;
            maxProfit=max(profit, maxProfit);
        }
        return maxProfit;
    }
};