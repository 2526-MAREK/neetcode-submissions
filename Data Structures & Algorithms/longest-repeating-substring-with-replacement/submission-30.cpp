#include <ranges>
#include <algorithm>

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        std::unordered_map<int8_t, int32_t> freqOfWindow;

int32_t res = 0;
int32_t l = 0;

freqOfWindow[s[l]] = 0 ;
for (int32_t r = 0; r < s.size(); ++r)
{
    
    freqOfWindow[s[r]] += 1;

    int32_t actualWindowSize = r - l + 1;
    int32_t mostFreqInWindow = std::ranges::max(freqOfWindow | std::views::values);
    if ((actualWindowSize - mostFreqInWindow) <= k)
    {
        res = std::max(res, actualWindowSize);

       

        
    }
    else
    {
        while ((actualWindowSize - mostFreqInWindow > k) && (l < r))
        {
            freqOfWindow[s[l]] -= 1;
            ++l;

            actualWindowSize = r - l + 1;
            mostFreqInWindow = std::ranges::max(freqOfWindow | std::views::values);
        }
    }
}

    return res;
    }
};
