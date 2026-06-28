class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int32_t> result(nums.size(), 0);

        int32_t pre = 1;
        int32_t post = 1; 

        result[0] = 1;


        for(int32_t i = 1 ; i < nums.size() ; ++ i)
        {
            result[i] = nums[i-1] * pre;
            pre *= nums[i-1];
        }

        for(int32_t i = nums.size() - 1 ; i >= 0 ; -- i)
        {
            result[i] *=  post;
            post *= nums[i];
        }

        return result;
    }
};
