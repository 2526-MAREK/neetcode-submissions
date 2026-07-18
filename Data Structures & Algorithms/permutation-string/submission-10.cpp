class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size())
            return false;


        std::vector<int32_t> freqS1(26,0);
        std::vector<int32_t> freqS2(26,0);

        for(const auto& letter : s1)
        {
            freqS1[letter - 'a'] += 1;
        }


        for(int32_t i = 0; i < s1.size(); ++i)
        {
            freqS2[s2[i] - 'a'] += 1;
        }

        if(freqS1 == freqS2)
                return true;

        int32_t l = 1;

        for(int32_t r = s1.size(); r < s2.size(); ++r)
        {
            freqS2[s2[l - 1] - 'a'] -= 1;

            freqS2[s2[r] - 'a'] += 1;

            if(freqS1 == freqS2)
                return true;

            ++l;

        }

        return false;
    }
};
