class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        std::unordered_set<int> my_set;

        for(int n : nums)
        {
            if(!my_set.insert(n).second)
            {
                return true;
            }
        }
        
        return false;
    }
};