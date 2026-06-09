class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {



        std::unordered_map<int32_t, int32_t> hashMap; // num : countOfNumberAppear

        for(const int32_t& num : nums)
        {
            if(hashMap.contains(num))
                hashMap[num] += 1;
            else
                hashMap[num] = 1;

        }

        std::vector<std::pair<int32_t, int32_t>> vec;
        vec.reserve(hashMap.size());

        for(auto const& [key, value] : hashMap)
        {
            vec.push_back({key,value});
        }
        std::sort(vec.begin(), vec.end(), [] (const auto& a, const auto&b){
            return a.second > b.second;
        });

        std::vector<int32_t> result;

        result.reserve(k);

        int32_t i = 0;
        for(auto const& vecVal : vec)
        {
            if(i == k)
                break;

            result.emplace_back(vecVal.first);
            ++i;
        }
            

        return result;

    }
};
