class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> mapOfAnagrams;

        vector<vector<string>> result;

        for(const auto& localString : strs)
        {
            std::vector<int32_t> mapOfString(26,0);

            for(const auto& localChar : localString)
            {
                 mapOfString[localChar - 'a'] += 1;

            }

            std::string keyOfMap = "";

            for (const auto& temp : mapOfString)
            {
                keyOfMap += std::to_string(temp) + '#';
            }

            mapOfAnagrams[keyOfMap].push_back(localString);


        } 

        for(const auto& [key, value] : mapOfAnagrams)
        {
            result.push_back(value);
        }

        return result;
    }
};
