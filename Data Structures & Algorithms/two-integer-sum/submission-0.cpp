class Solution {
public:
    std::vector<int32_t> twoSum(std::vector<int32_t>& nums, int32_t target) {
        
        std::unordered_set<int32_t>  result;

        for(int32_t i = 0; i < nums.size()  ; ++i)
        {
             for(int32_t j = 0; j < nums.size() ; ++j)
             {
                if((nums[i] + nums[j] == target) && (i != j) )
                {
                    result.insert(i);
                    result.insert(j);
                }
                    
             }
        }

        std::vector<int32_t> resultVector(result.begin(), result.end());


        std::sort(resultVector.begin(), resultVector.end());
        //std::cout << "j: " << j << " i: " << i << std::endl;
        return resultVector;
    }
};
