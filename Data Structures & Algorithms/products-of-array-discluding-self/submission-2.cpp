class Solution {
public:

    //in: [1;2;4;6]  
    //in: [a;b;c;d]

    //1pre = 1
    //2pre = 1 (1pre * a)
    //3pre = 2 (2pre * b)

    //1post = 1 
    //2post = 6 (1post*d)
    //3post =  24(2post*c)
    //4post = 48 (3post*b)
    
    //first we go through table from left to right ->
    //[e;f;g;h]  [1;1pre*a;2pre*b;3pre*c]  
    //[1;1;2;8]

    //now we go through table from right to left <-
    //out [e*4post;f*3post;g*2post;h*1post]
    //out [48;24;12;8]
    vector<int> productExceptSelf(vector<int>& nums) {
    std::vector<int32_t> output;

    output.reserve(nums.size());

    output.emplace_back(1);

    int32_t pre =1;
    

    for(int32_t i =0; i < nums.size()- 1; ++i)
    {
        output.emplace_back(nums[i]*pre);
        pre *= nums[i];
    }

    int32_t post = 1;
    for(int32_t i =nums.size()- 1; i >= 0; --i)
    {
        output[i] = output[i]*post;
        post *= nums[i];
    }

    return output;

    }
};
