class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int32_t l = 0;
        
        int32_t maxProfit = 0;

        for(int32_t r = l +1; r < prices.size(); ++r)
        {
            int32_t actual = prices[r] - prices[l];

            if((actual >= 0) && ( actual > maxProfit))
                maxProfit = actual;

            if(prices[r] < prices[l])
                l = r;

        }

        return maxProfit;
    }
};
