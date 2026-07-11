#include <ranges>

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        std::unordered_map<int8_t, int32_t> maxFreq;

        int32_t l = 0;
        int32_t res = 0;

        for(int32_t r = 0; r < s.size(); ++r)
        {
            maxFreq[s[r]] += 1;

            int32_t sizeOfWindow = r - l + 1;
            int32_t charReplacement = sizeOfWindow - std::ranges::max(maxFreq | std::views::values);

            while(charReplacement > k)
            {
                maxFreq[s[l]] -= 1;
                ++l;

                sizeOfWindow = r - l + 1;
                charReplacement = sizeOfWindow - std::ranges::max(maxFreq | std::views::values);

               

            }

             res = std::max(res, sizeOfWindow);

        }


        return res;

    }
};
