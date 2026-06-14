class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //index :
        int buy = 0,sell = prices.size() - 1;
        int max = INT_MAX,temp = 0;
        for(int price : prices){
            if(price<max)
                max = price;
            else if(temp<price-max)
                temp = price-max;
        }
        return temp;
    }
};