class Solution {
public:
    string minWindow(string s, string t) {


    if (s.size() < t.size())
        return "";

    if ((s.size() == 0) || (t.size() == 0))
        return "";


    std::unordered_map<int8_t, int32_t> hashMapT;

    std::unordered_map<int8_t, int32_t> hashMapS;

    for (const auto& temp : t)
    {
        hashMapT[temp] += 1;
    }

    int32_t need = hashMapT.size();
    int32_t have = 0;

    int32_t resL = -1;
    int32_t resR = -1;
    int32_t resSize = 9999;

    int32_t l = 0;

    for (int32_t r = 0; r < s.size(); ++r)
    {
        int8_t localChar = s[r];

        if (hashMapT.contains(localChar))
        {
            hashMapS[localChar] += 1;

            if (hashMapS[localChar] == hashMapT[localChar])
                have += 1;
        }


        while (have == need)
        {
            if (r - l + 1 < resSize)
            {
                resL = l;
                resR = r;
                resSize = r - l + 1;
            }

            if (hashMapS.contains(s[l]) && hashMapS[s[l]] > 0)
                hashMapS[s[l]] -= 1;

            if (hashMapT.contains(s[l]) && (hashMapT[s[l]] > hashMapS[s[l]]))
                have -= 1;

            ++l;
        }

    }

    std::string result = "";

    if ((resL >= 0) && (resR >= 0) && (resL <= resR))
    {
        for (int32_t i = resL; i <= resR; ++i)
            result.push_back(s[i]);
    }


    return result;

}
};
