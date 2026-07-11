#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int32_t l = 0;
        int32_t res = 0;
        std::unordered_set<int8_t> hashSet;

        for(int32_t r = 0; r < s.size() ; ++r )
        {
            while(hashSet.count(s[r]))
            {
                hashSet.erase(s[l]);
                ++l;
            }

            hashSet.insert(s[r]);
            int32_t sizeOfHashSet = hashSet.size();
            res = std::max(res, sizeOfHashSet);
        }

        return res;

    }
};
