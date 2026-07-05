class Solution {
public:
    bool isPalindrome(string s) {
        

        std::string word;
        for( int32_t i = 0; i < s.size(); ++i)
        {
            if(std::isalnum(s[i]))
            {
                word += std::tolower(s[i]);
            }
            

        }

        int32_t mid = 0;

        if(s.size() % 2)
        {
            mid = (s.size()-1)/2;
        }
        else
        {
            mid = s.size()/2;
        }

       
        int32_t r = word.size() -1 ;

       for( int32_t l = 0; l < mid +1; ++l)
        {

            if(word[l] != word[r])
                return false;

            --r;

        }

        return true;
    }
};
