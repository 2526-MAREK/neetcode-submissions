class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int32_t minPrice = prices[0];
        int32_t maxProfit = 0;
        int32_t maxProfitLocal = 0;

        for(int32_t i = 0; i < prices.size(); ++i)
        {
            if(prices[i] < minPrice)
                minPrice = prices[i];

            maxProfitLocal = prices[i] - minPrice;

            if(maxProfitLocal > maxProfit)
                maxProfit = maxProfitLocal;

        }

        return maxProfit;

    }
};
