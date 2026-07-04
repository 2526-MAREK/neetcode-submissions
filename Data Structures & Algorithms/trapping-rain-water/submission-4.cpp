class Solution {
public:
    int trap(vector<int>& height) {
        int32_t maxL = 0;
int32_t maxR = 0;

int32_t l = 0;
int32_t r = height.size() - 1;
int32_t result = 0;

while (l <= r)
{
    int32_t watterToAdd = 0;

    if (maxL <= maxR)
    {

        watterToAdd = std::min(maxL, maxR) - height[l];
        maxL = (height[l] > maxL) ? height[l] : maxL;
        ++l;

    }
    else
    {

        watterToAdd = std::min(maxL, maxR) - height[r];
        maxR = (height[r] > maxR) ? height[r] : maxR;
        --r;
    }


    result = (watterToAdd >= 0) ? result += watterToAdd : result;

}


return result;

    }
};
