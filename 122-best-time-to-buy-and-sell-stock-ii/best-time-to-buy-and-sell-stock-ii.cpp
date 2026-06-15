class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;int buy=0;
        for(int i = 1;i<prices.size();i++){
            if(prices[i]<prices[buy]){
                buy = i;
                continue;
            }
            else{
                ans += prices[i]-prices[buy];
                buy = i;
            }
        }
        return ans;
    }
};