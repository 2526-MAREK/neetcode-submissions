class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int32_t l = 0 ;
        int32_t r =l  +1;

        int32_t min = prices[l];
        int32_t max = 0;
        int32_t res = 0;

        

        while(r < prices.size())
        {
            min = std::min(prices[l], min);
            max = std::max(prices[r], max);

            if((max > min) && (prices[r] > prices[l]))
            {
                int32_t resLocal = max - min;
                res = std::max(res, resLocal);
            }
                

            if(prices[l] > prices[r])
            {
                l = r;
                ++r;
               max = 0;
               min = 999;
            }
            else
            {
                ++r;


            }
                

            // ++l;
            // ++r;


        }

        return res;
    }

    
};
