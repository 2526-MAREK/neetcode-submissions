class Solution {
public:
    string minWindow(string s, string t) {

    if ((s.size() == 0) || (t.size() == 0))
        return "";


    if (s.size() < t.size())
        return "";


    std::unordered_map<int8_t, int32_t> sContainer; // Char : countOfAppears
    std::unordered_map<int8_t, int32_t> tContainer; // Char : countOfAppears

    for (const auto& charLocal : t)
    {
        tContainer[charLocal] += 1;
    }

    int32_t l = 0;

    std::string result = "";
    int32_t shortes = 9999;
    int32_t have = 0;
    int32_t need = tContainer.size();

    for (int32_t r = 0; r < s.size(); ++r)
    {
        int8_t charLocal = s[r];

        sContainer[charLocal] += 1;

        if (tContainer.contains(charLocal) && sContainer[charLocal] == tContainer[charLocal])
            have += 1;



            while (have == need)
            {
                if ((r - l + 1) < shortes)
                {
                    shortes = r - l + 1;
                    result.clear();
                    for (int32_t i = l; i <= r; ++i)
                    {
                        result.push_back(s[i]);
                    }

                }


                sContainer[s[l]] -= 1;

                if (tContainer.contains(s[l]) && (sContainer[s[l]] < tContainer[s[l]]))
                    have -= 1;

                ++l;

            }



    }

    return result;
}
};
