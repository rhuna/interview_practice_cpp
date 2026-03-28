#include "subString.hpp"
int main()
{
    std::string s = "abcabcbb";
    subString substr;

    // Call function and print result
    std::cout << substr.lengthOfLongestSubstring(s) << std::endl; // Output: 3

    return 0;
}