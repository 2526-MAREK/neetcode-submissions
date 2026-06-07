class Solution {
public:
    bool isAnagram(std::string s, std::string t) {

        //2. Optimalized solution:
        std::unordered_map<int8_t, int32_t> hashMapS; // letter : countOfLetter
        std::unordered_map<int8_t, int32_t> hashMapT; // letter : countOfLetter

        for(const int8_t& letter : s)
        {
            if(hashMapS.contains(letter))
                hashMapS[letter] += 1;
            else
                hashMapS[letter] = 1;

        }

        

        for(const int8_t& letter : t)
        {
            if(hashMapT.contains(letter))
                hashMapT[letter] += 1;
            else
                hashMapT[letter] = 1;

        }

        if(hashMapS == hashMapT)
        {
            return true;
        }
        
        return false;

         //1.My solution second:
        // std::sort(s.begin(), s.end());
        // std::sort(t.begin(), t.end());
        
        // if(s == t)
        //     return true;

        // return false;




        //1.My solution first(not end):
        //Save to Vector, sort, compare two vector if equal return true if not return false
        // std::vector<int8_t> letterString1;
        // std::vector<int8_t> letterString2;

        // letterString1.reserve(s.size());
        // letterString2.reserve(s.size());

        // for(const int8_t& letter : s)
        // {
            
        //     letterString1.emplace_back(letter);
        // }

        // for(const int8_t& letter : t)
        // {
            
        //     letterString2.emplace_back(letter);
        // }

        // std::sort(letterString1.begin(), letterString1.end());
        // std::sort(letterString2.begin(), letterString2.end());

        // for(const int8_t& letter : letterString1)
        // {
            
        //     std::cout << letter << std::endl;
        // }

        // for(const int8_t& letter : letterString2)
        // {
            
        //     std::cout << letter << std::endl;
        // }


        
        //return false;
    }
};
