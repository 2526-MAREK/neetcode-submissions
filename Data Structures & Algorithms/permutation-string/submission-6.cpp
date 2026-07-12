class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size())
            return false;

        //m = length of s1, n length of s2
        std::vector<int32_t> mapOfS1String(26, 0); //space O(26)

        for(const auto& charLocal : s1) //time O(m)
        {
            mapOfS1String[charLocal - 'a'] += 1;
        }

        int32_t l = 0;
        int32_t r = s1.size();

        std::vector<int32_t> mapOfS2String(26, 0); //space O(26)

        for(int32_t i = l; i < r-1; ++i) //time O(m)
        {
                mapOfS2String[s2[i] - 'a'] += 1;

        }

        while(r <= s2.size()) //time O(n)
        {
             mapOfS2String[s2[r-1] - 'a'] += 1;
             

             if(mapOfS1String == mapOfS2String)
                return true;
            else
                {
                    mapOfS2String[s2[l] - 'a'] -= 1;
                    ++l;
                    ++r;
                }
        }

        
        return false;
    }
};
