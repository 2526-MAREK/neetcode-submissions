class Solution {
public:
    //HOW CAN WE IMPROVE ALGORITHM 
//     Yes, your algorithm **fulfills the requirements** for Time and Space complexity, and it works correctly **specifically under the provided constraints**.

    // Here is the evaluation based on the NeetCode/LeetCode constraints:

    // ### 1. Complexity Analysis
    // *   **Time Complexity:** **$O(m)$**, where $m$ is the total number of characters across all strings. 
    //     *   In `encode`, you visit each character once to build the string. 
    //     *   In `decode`, you use `string_view` (efficient) and copy each character exactly once into the final vector.
    // *   **Space Complexity:** **$O(m + n)$**.
    //     *   The encoded string takes $m$ (data) + $3n$ (prefixes) space.
    //     *   The decoded vector takes $m$ space to store the results.

    // ---

    // ### 2. Does it work with the Constraints?
    // The constraints are the key to why your specific logic works:
    // *   **Constraint:** `strs[i].length < 200`
    //     *   **Why it works:** Since no string is ever longer than 199 characters, your 3-digit prefix (`000` to `199`) will never naturally be `999`. Therefore, using `999` as a "stop" signal is safe **only because of this constraint**.
    // *   **Constraint:** `Any possible characters out of 256 valid ASCII`
    //     *   **Why it works:** Because you are using a **Length-Prefix** strategy. Even if a string contains numbers, symbols, or null characters, your decoder doesn't care; it simply reads the prefix and "jumps" that many characters ahead.

    // ---

    // ### 3. Potential Improvements (The "Generalized" Way)
    // The prompt asks: *"Could you write a generalized algorithm to work on any possible set of characters?"*

    // While your code works for the `length < 200` constraint, it is not "generalized" for **any** length. If a string had 1,000 characters, your `substr(..., 3)` logic would break.

    // The standard industry approach for this problem (to handle any length and any characters) is the **Length + Delimiter** method:

    // **Example: `length + "#" + string`**
    // *   Input: `["Hello", "World"]`
    // *   Encoded: `5#Hello5#World`

    // **Why this is better:**
    // 1.  **No length limit:** The length can be 5, 50, or 50000. You just read characters until you hit the `#`.
    // 2.  **No Sentinel needed:** You don't need a `999` at the end. You simply stop when you reach the end of the encoded string.
    // 3.  **Character Safe:** Even if the string contains a `#`, it doesn't matter because the decoder only looks for a `#` *after* it knows it is looking for a length.

    // ### Summary
    // Your code is **correct** and **efficient** ($O(m)$ time) for the specific test case constraints provided. 

    // **One small tip for C++ performance:**
    // In your `encode` function, you should use `result.reserve(...)` before the loop.
    // ```cpp
    // // Optimization: Prevent multiple memory re-allocations
    // size_t total_needed = 0;
    // for (const auto& s : strs) total_needed += s.size() + 3;
    // result.reserve(total_needed + 3);
    // ```
    // This keeps the time complexity strictly linear and avoids the overhead of the string resizing itself as it grows.
    string encode(vector<string>& strs) {
        string result = "";


        for (const auto& str : strs)
        {
            std::string prefix = "";

            if(str.size() < 10)
                prefix = "00" + std::to_string(str.size());
            else if ((str.size() >= 10) && (str.size() < 100))
                prefix = "0" + std::to_string(str.size());
            else
                prefix = std::to_string(str.size());

            result += prefix + str;

        }


        result += "999";

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        std::string_view sv(s);

        std::string_view firstPrefix = sv.substr(0, 3);

        int32_t firstPrefixNumber;

        std::from_chars(firstPrefix.data(), firstPrefix.data() + firstPrefix.size(), firstPrefixNumber);

        if (firstPrefixNumber == 999)
            {
                return result;
            }

        std::string_view firstWord = sv.substr(3, firstPrefixNumber);

        result.push_back(std::string(firstWord));




        int32_t i = 1;
        int32_t countedPrefixNumber = firstPrefixNumber;


        while (true)
        {
            std::string_view prefixLocal = sv.substr(3 *i + countedPrefixNumber, 3);

            int32_t prefixNumberLocal;

            std::from_chars(prefixLocal.data(), prefixLocal.data() + prefixLocal.size(), prefixNumberLocal);

            if (prefixNumberLocal == 999)
                break;

            
            //3 + 3 *i 
            std::string_view word = sv.substr(3 + 3 * i + countedPrefixNumber, prefixNumberLocal);

            countedPrefixNumber += prefixNumberLocal;
            ++i;

            result.push_back(std::string(word));

        }
        return result;
    }
};