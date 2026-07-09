#include <ranges>   

class Solution {
public:
    int characterReplacement(string s, int k) {
        //sliding window solution 
    int32_t l = 0;
    int32_t res = 0;

    std::unordered_map<int8_t, int32_t> count;

    for (int32_t r = 0; r < s.size(); ++r)
    {
        count[s[r]] += 1;

        int32_t sizeOfWindow = r - l + 1;

        int32_t maxValue = std::ranges::max(count | std::views::values);

        while (((sizeOfWindow - maxValue)>k) &&(l < s.size()))
        {
            count[s[l]] -= 1;
            l += 1;

            maxValue = std::ranges::max(count | std::views::values);

            sizeOfWindow = r - l + 1;
        }


        res = std::max(res, sizeOfWindow);



    }

    return res;



}
};