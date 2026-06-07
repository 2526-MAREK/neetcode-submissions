class Solution {
public:


    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::string> strsSorted = strs;

    std::vector<std::vector<std::string>> strsResult;

    strsSorted.reserve(strs.size());

    for (std::string& str : strsSorted)
    {
        std::sort(str.begin(), str.end());
    }



    std::unordered_map<std::string, int32_t> hashMap; //sortedStrs : index

    for (int32_t i = 0; i < strs.size(); ++i)
    {
        if (hashMap.contains(strsSorted[i]))
        {
            strsResult[hashMap[strsSorted[i]]].push_back(strs[i]);
            //hashMap[strsSorted[i]] += 1;
        }
        else
        {
            hashMap[strsSorted[i]] = strsResult.size();
            strsResult.push_back({ strs[i] });
        }

    }



    return strsResult;

}
};
