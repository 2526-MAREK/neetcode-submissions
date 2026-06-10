#include <ranges>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<std::vector<int32_t>> result; // count of appears : particular number 

result.reserve(nums.size());

for (int32_t i = 0; i <= nums.size(); ++i)
{
    result.push_back({});
}

std::unordered_map<int32_t, int32_t> hashMap; //number : countOfApeears

for (const int32_t& num : nums)
{
    if (hashMap.contains(num))
        hashMap[num] += 1;
    else
        hashMap[num] = 1;


}

for (const auto& [key, value] : hashMap)
{
    result[value].push_back(key);
}

std::vector<int32_t> returnResult;

returnResult.reserve(k);

int32_t i = 0;
for (auto const& row : result | std::views::reverse)
{
    if (i == k)
        break;

    for (auto const& num : row)
    {
        
            returnResult.push_back(num);
            ++i;

        
    }
    
    

}

return returnResult;

    }
};