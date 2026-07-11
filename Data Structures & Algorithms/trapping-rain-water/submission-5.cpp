class Solution {
public:
    int trap(vector<int>& height) {
        int32_t maxL = 0;
        int32_t maxR = 0;
        int32_t res = 0;
        int32_t l =0;
        int32_t r = height.size() -1;


        while(l <= r)
        {
            int32_t minLR = std::min(maxL, maxR);

            if(maxL <= maxR)
            {
                

                int32_t resLocal = minLR - height[l];

                res += (resLocal > 0) ? resLocal : 0;

                maxL = std::max(maxL, height[l]);
                ++l;

            }
            else
            {
               

                int32_t resLocal = minLR - height[r];

                res += (resLocal > 0) ? resLocal : 0;

                 maxR = std::max(maxR, height[r]);

                --r;
            }
        }


        return res;

    }
};
