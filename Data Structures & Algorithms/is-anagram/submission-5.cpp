class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<int8_t, int32_t> hashMap1; //char ; countOfAppears
        std::unordered_map<int8_t, int32_t> hashMap2;

        for(const auto& charLocal : s)
        {
            hashMap1[charLocal] += 1;

        }

        for(const auto& charLocal : t)
        {
            hashMap2[charLocal] += 1;
            
        }

        if(hashMap1 == hashMap2)
            return true;
        else
            return false;

    }
};
