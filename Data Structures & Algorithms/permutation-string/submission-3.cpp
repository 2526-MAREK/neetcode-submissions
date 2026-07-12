class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size())
            return false;

        std::vector<int32_t> mapOfS1String(26, 0);

        for(const auto& charLocal : s1)
        {
            mapOfS1String[charLocal - 'a'] += 1;
        }

        int32_t l = 0;
        int32_t r = s1.size();

        while(r <= s2.size())
        {
             std::vector<int32_t> mapOfS2String(26, 0);
             for(int32_t i = l; i < r; ++i)
             {
                mapOfS2String[s2[i] - 'a'] += 1;

             }

             if(mapOfS1String == mapOfS2String)
                return true;
            else
                {
                    ++l;
                    ++r;
                }
        }

        
        return false;
    }
};
