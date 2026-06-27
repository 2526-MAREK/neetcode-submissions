class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result ="";

        for(const auto& str : strs)
        {
            result += std::to_string(str.size()) + '#' +str;
        }

        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;
        std::string_view sv(s);

        int32_t begin =0;
        int32_t length = -1;

        for(int32_t i = 0; i< s.size(); ++i)
        {
            ++length;
            if(s[i] == '#')
            {
                string_view wordNum = sv.substr(begin, length);

                int lengthOfWord;

                std::from_chars(wordNum.data(), wordNum.data() + wordNum.size(), lengthOfWord);

                std::string_view word = sv.substr(i+1, lengthOfWord);
                result.push_back(std::string(word));
                begin = i +1 + lengthOfWord;
                i = begin;
                length = 0;
            }

        }
        return result;
    }
};
