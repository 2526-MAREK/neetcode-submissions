class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<int32_t> hashSet;

        int32_t res = 0;
        int32_t l = 0;

        for(int32_t r = 0 ; r < s.size() ; ++r)
        {

            while(hashSet.count(s[r]))
            {
                hashSet.erase(s[l]);
                ++l;
            }

            res = std::max(r - l + 1, res);

            hashSet.insert(s[r]);


        }

        return res;
    }
};
