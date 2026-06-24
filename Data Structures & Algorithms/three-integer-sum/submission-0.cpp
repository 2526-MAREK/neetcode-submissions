class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector < std::vector<int32_t>> result;

    std::sort(nums.begin(), nums.end());

    int j = 0;
    int k = nums.size() - 1;
    int target;


    for (int32_t i = 0; i < nums.size(); ++i)
    {
        if ((i > 0) && (nums[i - 1] == nums[i]))
            continue;

        j = i+1;
        k = nums.size() - 1;
        while (j < k)
        {
            
            /*if ((j > 0) && (nums[j - 1] == nums[j]))
                continue;

            if ((k > 0) && (nums[k - 1] == nums[k]))
                continue;*/

            target = nums[j] + nums[k] +nums[i];

            

            if (target < 0)
            {
                ++j;
            }
            else if (target > 0)
            {
                --k;
            }
            else 
            {
                std::vector<int32_t> tempVec;

                tempVec.push_back(nums[i]);
                tempVec.push_back(nums[j]);
                tempVec.push_back(nums[k]);

                result.push_back(tempVec);

                // Move pointers
                ++j;
                --k;

                // Skip duplicates for the second element
                while (j < k && nums[j] == nums[j - 1])
                    ++j;

                // Skip duplicates for the third element
                while (j < k && nums[k] == nums[k + 1])
                    --k;

            }


        }


    }


    return result;

    }
};
