class Solution {
public:
    std::vector<int32_t> twoSum(std::vector<int32_t>& nums, int32_t target) {
        
    //1. chat bot solution
    //     for (int i = 0; i < nums.size(); i++) {
    //     for (int j = i + 1; j < nums.size(); j++) {
    //         if (nums[i] + nums[j] == target) {
    //             return {i, j}; // Immediately returns the two indices as a vector
    //         }
    //     }
    // }
    // return {}; // Return empty if no solution is found

    //2. my solution
        // std::unordered_set<int32_t>  result;

        // for(int32_t i = 0; i < nums.size()  ; ++i)
        // {
        //      for(int32_t j = 0; j < nums.size() ; ++j)
        //      {
        //         if((nums[i] + nums[j] == target) && (i != j) )
        //         {
        //             result.insert(i);
        //             result.insert(j);
        //         }
                    
        //      }
        // }

        // std::vector<int32_t> resultVector(result.begin(), result.end());


        // std::sort(resultVector.begin(), resultVector.end());
        // //std::cout << "j: " << j << " i: " << i << std::endl;
        // return resultVector;


    //3. optimalize solution
    std::unordered_map<int32_t, int32_t> hashMap;   //value : index

    for(int32_t i = 0 ; i< nums.size(); ++i)
    {
        int32_t diff = target - nums[i];

        if(hashMap.count(diff))
            return {hashMap[diff], i};

        hashMap[nums[i]] = i;
    }

    return {};

    }
};
