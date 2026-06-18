class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        std:unordered_set<int32_t> hashSet;

        for(const int32_t& num : nums)
        {
            hashSet.insert(num);
        }
        
        int longest = 0;

        for(const int32_t& num : nums)
        {
            int length = 1;

            if(hashSet.contains(num - 1))
            {
                length += 1;
                int numTemp = num;
                while(hashSet.contains(numTemp + 1))
                {
                    ++length;
                    ++numTemp;
                }

                


            }

            if(length > longest)
                    longest = length;

        }


        return longest;

    }
};
