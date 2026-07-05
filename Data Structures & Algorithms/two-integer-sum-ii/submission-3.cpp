class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int32_t l = 0;
        int32_t r = numbers.size() - 1;
        int32_t result = 0 ;
        while(l < r)
        {
            result = numbers[l] + numbers[r];
            if(result > target)
                --r;
            else if(result < target)
                ++l;
            else
                return std::vector({l +1, r +1});
        }
    }
};
