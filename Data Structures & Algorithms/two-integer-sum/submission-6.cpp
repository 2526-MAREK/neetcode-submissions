class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int32_t, int32_t> hashMap;
        std::vector<int32_t> result;
        result.reserve(2);

        for(int32_t i = 0; i < nums.size(); ++i)
        {
            hashMap[nums[i]] = i;
        }

        for(int32_t i = 0; i < nums.size(); ++i)
        {
           int32_t browseNum = target - nums[i];
           if(hashMap.count(browseNum) && (i != hashMap[browseNum]) )
           {
                
                result.push_back(i);
                result.push_back(hashMap[browseNum]);
                break;
           }
           
           
        }

        return result;
    }
};
