class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;

        std::sort(nums.begin(), nums.end());

        for(int32_t i =0 ; i < nums.size(); ++i)
        {
            if((i > 0) && (nums[i - 1] == nums[i]))
                continue;

            int32_t l = i + 1;
            int32_t r = nums.size() - 1;

            while(l < r)
            {
                int32_t target = nums[i] + nums[l] + nums[r];

                if(target < 0)
                {
                    ++l;
                }
                else if(target > 0)
                {
                    --r;
                }
                else
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;

                    while( (l < nums.size()) && (nums[l-1] == nums[l]) )
                    ++l;

                    while( (r > 0) &&  (r < nums.size() - 1) &&(nums[r+1] == nums[r]) )
                        --r;
                }

                
            }
        }

        return result;
    }
};
