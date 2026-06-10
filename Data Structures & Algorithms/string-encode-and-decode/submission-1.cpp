class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";


        for (const auto& str : strs)
        {
            std::string prefix = "";

            if(str.size() < 10)
                prefix = "00" + std::to_string(str.size());
            else if ((str.size() >= 10) && (str.size() < 100))
                prefix = "0" + std::to_string(str.size());
            else
                prefix = std::to_string(str.size());

            result += prefix + str;

        }


        result += "999";

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        std::string_view sv(s);

        std::string_view firstPrefix = sv.substr(0, 3);

        int32_t firstPrefixNumber;

        std::from_chars(firstPrefix.data(), firstPrefix.data() + firstPrefix.size(), firstPrefixNumber);

        if (firstPrefixNumber == 999)
            {
                return result;
            }

        std::string_view firstWord = sv.substr(3, firstPrefixNumber);

        result.push_back(std::string(firstWord));




        int32_t i = 1;
        int32_t countedPrefixNumber = firstPrefixNumber;


        while (true)
        {
            std::string_view prefixLocal = sv.substr(3 *i + countedPrefixNumber, 3);

            int32_t prefixNumberLocal;

            std::from_chars(prefixLocal.data(), prefixLocal.data() + prefixLocal.size(), prefixNumberLocal);

            if (prefixNumberLocal == 999)
                break;

            
            //3 + 3 *i 
            std::string_view word = sv.substr(3 + 3 * i + countedPrefixNumber, prefixNumberLocal);

            countedPrefixNumber += prefixNumberLocal;
            ++i;

            result.push_back(std::string(word));

        }
        return result;
    }
};
