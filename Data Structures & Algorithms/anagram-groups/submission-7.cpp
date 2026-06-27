class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hashMap;


    for (const auto& str : strs)
    {
        std::string tempStr(27, 0);

        for (const auto& charLocal : str)
        {

            tempStr[charLocal - 'a'] += 1;

        
        }

        hashMap[tempStr].push_back(str);

    }

    vector<vector<string>> result;

    for (const auto& [key, value] : hashMap)
    {
        result.push_back(value);
    }

    return result;

    }
};
