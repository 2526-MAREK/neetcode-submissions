class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        std::unordered_set<int32_t> hashSet;

        for(const auto& num: nums)
        {
            if(hashSet.count(num))
                return true;

            hashSet.insert(num);
        }

        return false;
    }
};