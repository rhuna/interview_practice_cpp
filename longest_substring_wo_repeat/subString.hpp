#include <iostream>      // for std::cout
#include <string>        // for std::string
#include <unordered_map> // hash map (O(1) lookups)
#include <algorithm>     // for std::max



class subString{
public:

    subString(){};

    ~subString(){};

    // Function to find the length of the longest substring without repeating characters
    int lengthOfLongestSubstring(const std::string &s)
    {

        // Hash map to store: character -> last index where it appeared
        // Example: {'a' : 3, 'b' : 5}
        std::unordered_map<char, int> lastSeen;

        int left = 0;   // Left boundary of sliding window
        int maxLen = 0; // Stores the maximum length found

        // Right pointer expands the window one character at a time
        for (int right = 0; right < s.length(); right++)
        {

            char current = s[right]; // current character we are processing

            /*
            Check if:
            1. We've seen this character before
            2. AND it is inside our current window

            Why check >= left?
            Because if it was seen BEFORE the current window,
            we don't care about it anymore.
            */
            if (lastSeen.count(current) && lastSeen[current] >= left)
            {

                // Move the left pointer to 1 position AFTER the duplicate
                // This removes the duplicate from the window
                left = lastSeen[current] + 1;
            }

            // Update the last seen index of the current character
            lastSeen[current] = right;

            /*
            Calculate current window size:
            right - left + 1

            Example:
            left = 2, right = 5 → length = 4
            */
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};


