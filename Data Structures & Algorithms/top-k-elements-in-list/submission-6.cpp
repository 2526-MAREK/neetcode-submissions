#include <ranges>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int32_t, int32_t> hashMap; //number : countOfAppeares

        std::vector<std::vector<int32_t>> result(nums.size() + 1);
        std::vector<int32_t> answer;


        for(int32_t i =0; i< nums.size(); ++i)
        {
            hashMap[nums[i]] += 1;

        }

        for(auto const& [key, value] : hashMap)
        {
            result[value].push_back(key);
        }

        int32_t i = 0;
        for(auto const& row : result | std::views::reverse)
        {
            for(auto const& num : row)
            {
                if(i == k)
                 break;

                answer.push_back(num);
                ++i;
            }
        }

        return answer;


    }
};
