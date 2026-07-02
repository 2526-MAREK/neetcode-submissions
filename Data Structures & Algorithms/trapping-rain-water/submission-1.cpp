class Solution {
public:
    int trap(vector<int>& height) {
        int32_t l = 0;
        int32_t r = height.size() - 1;

        int32_t maxL = height[l];
        int32_t maxR = height[r];

        int32_t waterToAdd = 0;

        int32_t res = 0;

        while(l < r)
        {
            if(maxL <= maxR)
            {
                ++l;

                waterToAdd = maxL - height[l];
                res += (waterToAdd >= 0) ? waterToAdd : 0;
                maxL = (height[l] > maxL) ? height[l] : maxL;

            }
            else
            {
                
                --r;
                waterToAdd = maxR - height[r];
                res += (waterToAdd >= 0 ) ? waterToAdd : 0;
                maxR = (height[r] > maxR) ? height[r] : maxR;
            }
                
            


        }

        return res;
    }
};
