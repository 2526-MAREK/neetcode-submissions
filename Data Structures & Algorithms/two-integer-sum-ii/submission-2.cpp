class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        std::vector<int32_t> result(2, 1);

        int32_t left = 0;
        int32_t right = numbers.size() -1;

        while(true)
        {
            if(numbers[left] + numbers[right] > target)
                --right;
            else if((left < right)&& (numbers[left] + numbers[right] == target))
            {
                result[0] = left +1;
                result[1] = right +1;
                return result;
            }  
            else
                ++left;

        }

        
        

    }
};
