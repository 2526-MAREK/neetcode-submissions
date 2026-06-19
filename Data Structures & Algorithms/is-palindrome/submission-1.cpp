class Solution {
public:
    bool isPalindrome(string s) {
        for(char& c : s)
        {
            c = std::tolower((unsigned char) c);
        }

        std::erase_if(s, [](unsigned char c){
            return !std::isalnum(c);
        });

        int mapSize = 0;
        if(s.size() % 2)
        {
            int k = s.size() -1;
            mapSize = k/2;
        }
        else
        {
            mapSize = s.size()/2;
        }
        
        int j = 0;

        for(int32_t i = s.size() -1; i >= mapSize ; --i )
        {
            if(s[i] != s[j])
                return false;

            ++j;
        }

        return true;
    }
};
