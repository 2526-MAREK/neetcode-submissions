class Solution {
public:
    int maxArea(vector<int>& heights) {
        int biggestField = 0;
        int left = 0;
        int right = heights.size() - 1; 

        while(left < right)
        {
            int minValue = heights[left];
            if(heights[left] < heights[right])
                minValue = heights[left];
            else if(heights[left] > heights[right])
                minValue = heights[right];
            
            int field = (right - left) * minValue;

            if(field >= biggestField)
                biggestField = field;

            if(heights[left]< heights[right])
                ++left;
            else if(heights[left]> heights[right])
                --right;
            else
            {
                ++left;
                --right;
            }
        }

        return biggestField;
    }
};
