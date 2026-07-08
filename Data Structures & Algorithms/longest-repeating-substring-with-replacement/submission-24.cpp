class Solution {
public:
    int characterReplacement(string s, int k) {

    
    int32_t l = 0;
    int32_t r = 0;

    
    
    int32_t res = 0;

    while (l < s.size())
    {
        std::unordered_map<int8_t, int32_t> tempContainer;//char : count of appears
        int32_t sizeOfWindow = 0;
        int32_t pr = 0;
        int32_t mostFrequent = 0;

        for (int32_t i = l; (i <= r) && (i < s.size()) ; ++i)
        {
            ++sizeOfWindow;
            tempContainer[s[i]] += 1;

            if (tempContainer[s[i]] > mostFrequent)
                mostFrequent = tempContainer[s[i]];
        }

        pr = sizeOfWindow - mostFrequent;

        if (pr <= k)
        {
            if (sizeOfWindow > res)
            {
                res = sizeOfWindow;
            }

            if (r < s.size())
                ++r;
            else
                ++l;
        }
        else
        {
            ++l;
        }
            
    }

    return res;

}
};
