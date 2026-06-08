class Solution {
public:


    
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        //---------------------------------------------------------    
        //3. second optmialize solution 
    //     unordered_map<string, vector<string>> hashMap;

    // for (const string& s : strs) {
    //     // 1. Create a frequency array of 26 zeros
    //     vector<int> counts(26, 0);
    //     for (char c : s) {
    //         counts[c - 'a']++;
    //     }

    //     // 2. Convert that array into a unique string key
    //     string key = "";
    //     for (int i = 0; i < 26; i++) {
    //         key += to_string(counts[i]) + "#"; // The '#' prevents "1, 11" from looking like "11, 1"
    //     }

    //     // 3. Now you can use unordered_map!
    //     hashMap[key].push_back(s);
    // }

    // vector<vector<string>> result;
    // for (auto& pair : hashMap) {
    //     result.push_back(pair.second);
    // }
    // return result;

//---------------------------------------------------------    
    //2. Optimalize solution(problaby this is not efficient beacuse we use map, here we need to use a hashMap)
//     std::vector<std::vector<std::string>> strsResult;

// map<vector<int>, vector<string>> hashMap;

// for (const std::string& str : strs)
// {
//     vector<int> counts(26, 0);

//     for (char ch : str) {
//         counts[ch - 'a']++;
//     }



//     hashMap[counts].push_back(str);

// }




// for (auto& [key, value] : hashMap) {
//     strsResult.push_back(std::move(value));
// }

// return strsResult;

//---------------------------------------------------------    
//1. My solution
//     To evaluate the complexity, let's define two variables:
// *   **$N$**: The number of strings in the input vector (`strs.size()`).
// *   **$K$**: The maximum length of a single string in the input.

// ---

// ### 1. Time Complexity: $O(N \cdot K \log K)$

// Here is the step-by-step breakdown:

// 1.  **Copying the vector (`strsSorted = strs`):** To copy $N$ strings of length $K$, it takes **$O(N \cdot K)$**.
// 2.  **Sorting each string:** 
//     *   You iterate through $N$ strings.
//     *   Sorting a single string of length $K$ takes $O(K \log K)$.
//     *   Total for this loop: **$O(N \cdot K \log K)$**.
// 3.  **Building the Hash Map and Result:**
//     *   You iterate through $N$ strings.
//     *   **Hashing the string:** To look up or insert a string of length $K$ into an `unordered_map`, the string must be hashed, which takes $O(K)$.
//     *   **Vector Operations:** `push_back` on the result vector and map operations are $O(1)$ average, but string copying into the result takes $O(K)$.
//     *   Total for this loop: **$O(N \cdot K)$**.

// **Total:** $O(N \cdot K) + O(N \cdot K \log K) + O(N \cdot K) \approx$ **$O(N \cdot K \log K)$**.

// ---

// ### 2. Space Complexity: $O(N \cdot K)$

// The space complexity is determined by how much extra memory you allocate relative to the input:

// 1.  **`strsSorted` vector:** Stores $N$ strings of length $K$. Space: **$O(N \cdot K)$**.
// 2.  **`strsResult` vector:** This is your output. It stores all the characters from the original input. Space: **$O(N \cdot K)$**.
// 3.  **`hashMap`:** In the worst case (where there are no anagrams), the map stores $N$ keys. Each key is a string of length $K$. Space: **$O(N \cdot K)$**.

// **Total:** **$O(N \cdot K)$**.

// ---

// ### Summary Table

// | Component | Time Complexity | Space Complexity |
// | :--- | :--- | :--- |
// | **String Sorting** | $O(N \cdot K \log K)$ | $O(N \cdot K)$ (for `strsSorted`) |
// | **Hash Map Grouping** | $O(N \cdot K)$ | $O(N \cdot K)$ (for `hashMap`) |
// | **Total** | **$O(N \cdot K \log K)$** | **$O(N \cdot K)$** |

// ---


    std::vector<std::string> strsSorted = strs;

    std::vector<std::vector<std::string>> strsResult;

    strsSorted.reserve(strs.size());

     //TIME:o(n) SPACE: O(m * n)
    for (std::string& str : strsSorted)
    {
        std::sort(str.begin(), str.end());
    }



    std::unordered_map<std::string, int32_t> hashMap; //sortedStrs : index

    for (int32_t i = 0; i < strs.size(); ++i)
    {
        if (hashMap.contains(strsSorted[i]))
        {
            strsResult[hashMap[strsSorted[i]]].push_back(strs[i]);
            //hashMap[strsSorted[i]] += 1;
        }
        else
        {
            hashMap[strsSorted[i]] = strsResult.size();
            strsResult.push_back({ strs[i] });
        }

    }



    return strsResult;

}
};
