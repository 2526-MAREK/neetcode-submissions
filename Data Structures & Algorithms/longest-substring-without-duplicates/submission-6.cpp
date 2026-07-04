class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<std::unordered_set<int8_t>> hashSet(1);


        int32_t longestLength = 0;
        int32_t countOfWord = 0;
        int32_t l = 0;
        int32_t r = l +1;
        
        hashSet[countOfWord].insert(s[l]);

        while((l < r) && (r < s.size()))
        {
            if(hashSet[countOfWord].count(s[r]))
                {

                    hashSet.push_back(std::unordered_set<int8_t>());
                    ++countOfWord;
                    ++l;
                    r = l +1;
                    hashSet[countOfWord].insert(s[l]);
                    
                }
            else
            {
                hashSet[countOfWord].insert(s[r]);
                ++r;
            }
              
        }


        if(s.size() == 0)
            return 0;

        for(const auto& vec : hashSet)
        {
            longestLength = (vec.size() > longestLength) ? vec.size() : longestLength; 
        }

        return longestLength;
    }
};
