class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        std::unordered_set<int32_t> hashSet;

        for(const auto& num : nums)
        {
            hashSet.insert(num);       
        }

        int32_t longest = 0;
        for(int32_t i = 0; i< nums.size() ; ++i)
        {
            int32_t length = 0;

            if(!hashSet.count(nums[i] - 1))
            {
                ++length;

                while(hashSet.count(nums[i] + length))
                {
                    ++length;
                } 

                if(length > longest)
                    longest = length;


            }
        }

        return longest;

    }
};
