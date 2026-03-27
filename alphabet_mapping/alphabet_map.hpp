#include <iostream>
#include <vector>





class AlphaMap{
    public:
        AlphaMap(){};
        ~AlphaMap(){};


        //helper//
        int countDecodings(const std::string &s)
        {
            // Get the total number of characters in the input string.
            // Example:
            //   s = "111"
            //   n = 3
            //
            // This tells us how many positions we need to process.
            int n = s.size();

            // Create a dynamic programming array named dp with size n + 1.
            //
            // Why n + 1 instead of just n?
            // Because dp[i] represents:
            //   "the number of ways to decode the first i characters of the string"
            //
            // That means:
            //   dp[0] = number of ways to decode the first 0 characters
            //   dp[1] = number of ways to decode the first 1 character
            //   dp[2] = number of ways to decode the first 2 characters
            //   ...
            //   dp[n] = number of ways to decode the entire string
            //
            // We fill the whole vector with 0 initially because before doing any work,
            // we assume there are zero known decoding ways for every prefix.
            //
            // Example for s = "111" (n = 3):
            //   dp has size 4
            //   indices:   0  1  2  3
            //   values:   [0, 0, 0, 0]
            std::vector<int> dp(n + 1, 0);

            // Base case:
            // dp[0] = 1 means there is exactly one way to decode an empty string.
            //
            // That may sound strange at first, but in dynamic programming,
            // this is a standard and necessary setup.
            //
            // Why 1 instead of 0?
            // Because when building larger answers, we want the empty prefix
            // to contribute one valid starting state.
            //
            // Think of it as:
            //   "There is one way to do nothing."
            //
            // This helps formulas like:
            //   dp[i] += dp[i - 2]
            // work correctly when the first two characters form a valid decode.
            //
            // Example:
            //   s = "12"
            //   "12" can be decoded as "L"
            //   To count that properly, dp[2] may need to add dp[0].
            //   If dp[0] were 0, that valid decoding would be lost.
            dp[0] = 1;

            // Base case:
            // dp[1] = 1 means the first character has exactly one valid decoding.
            //
            // This works because the problem states the string is guaranteed decodable.
            // So we do not have to worry here about invalid starting cases like "0".
            //
            // Example:
            //   s = "1"
            //   first character '1' maps to 'a'
            //   so dp[1] = 1
            //
            // More conceptually:
            //   dp[1] = number of ways to decode the first 1 character.
            //
            // Since one valid non-zero digit corresponds to exactly one letter,
            // there is exactly one way to decode it.
            dp[1] = 1;

            // At this point, for a string like "111":
            //   dp = [1, 1, 0, 0]
            //
            // Meaning:
            //   dp[0] = 1  -> empty prefix
            //   dp[1] = 1  -> first character decoded in one way
            //   dp[2] and dp[3] still need to be computed

            // Start a loop from i = 2 up to i = n.
            //
            // Why start at 2?
            // Because dp[0] and dp[1] are base cases already known.
            // Starting from 2, each step computes the number of decoding ways
            // for the first i characters.
            //
            // Example:
            //   if s = "111", n = 3
            //   loop runs for:
            //      i = 2
            //      i = 3
            //
            // At each iteration, we consider:
            //   1. Can the current single digit be decoded alone?
            //   2. Can the current pair of digits be decoded together?
            for (int i = 2; i <= n; i++)
            {
                // -------------------------
                // Check one-digit decode
                // -------------------------
                //
                // s[i - 1] is the current character, because string indices are 0-based
                // while dp indices are 1-based in meaning.
                //
                // Example:
                //   s = "111"
                //
                //   i = 2  -> looking at s[1], which is the 2nd character
                //   i = 3  -> looking at s[2], which is the 3rd character
                //
                // We check if s[i - 1] is not '0'.
                //
                // Why?
                // Because a single digit can only be decoded if it is between '1' and '9'.
                // The digit '0' cannot stand alone as a letter.
                //
                // Valid single-digit examples:
                //   '1' -> a
                //   '2' -> b
                //   ...
                //   '9' -> i
                //
                // Invalid single-digit example:
                //   '0' -> no letter by itself
                if (s[i - 1] != '0')
                {
                    // If the current single digit is valid,
                    // then every way to decode the first (i - 1) characters
                    // can be extended by decoding this last digit as one letter.
                    //
                    // So we add dp[i - 1] to dp[i].
                    //
                    // Meaning:
                    //   number of ways ending with a valid one-digit decode
                    //   = all the ways we could decode the previous prefix
                    //
                    // Example:
                    //   s = "111"
                    //
                    //   At i = 2:
                    //     current digit is '1'
                    //     valid single-digit decode
                    //     dp[2] += dp[1]
                    //     dp[2] += 1
                    //
                    //   This corresponds to taking the decoding of "1"
                    //   and appending another "1" as its own letter.
                    dp[i] += dp[i - 1];
                }

                // -------------------------
                // Check two-digit decode
                // -------------------------
                //
                // Build a two-digit number from s[i - 2] and s[i - 1].
                //
                // Example:
                //   if the characters are '1' and '2':
                //      ('1' - '0') = 1
                //      ('2' - '0') = 2
                //      twoDigit = 1 * 10 + 2 = 12
                //
                // Why subtract '0'?
                // Because characters like '1' and '2' are stored as ASCII/character codes,
                // not as integer numeric values directly.
                //
                //   '1' - '0' = 1
                //   '2' - '0' = 2
                //
                // So this line converts two character digits into an actual integer.
                int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

                // A two-digit decode is valid only if the number is between 10 and 26 inclusive.
                //
                // Why 10 to 26?
                // Because the mapping is:
                //   1  -> a
                //   2  -> b
                //   ...
                //   26 -> z
                //
                // So valid two-digit examples are:
                //   10, 11, 12, ..., 26
                //
                // Invalid examples:
                //   01  -> not allowed
                //   06  -> not allowed
                //   27  -> too large
                //   30  -> no letter mapping
                //
                // If the pair forms a valid number, then every way to decode
                // the first (i - 2) characters can be extended by decoding
                // these last two characters together as one letter.
                if (twoDigit >= 10 && twoDigit <= 26)
                {
                    // Add the number of ways to decode the prefix ending two positions earlier.
                    //
                    // Why dp[i - 2]?
                    // Because if the last two characters are being treated as one unit,
                    // then the rest of the string before them is the first (i - 2) characters.
                    //
                    // Example:
                    //   s = "111"
                    //
                    //   At i = 2:
                    //     last two chars = "11"
                    //     valid two-digit decode
                    //     dp[2] += dp[0]
                    //     dp[2] += 1
                    //
                    //   So now dp[2] gets:
                    //     one way from single-digit extension
                    //     one way from two-digit extension
                    //
                    //   total dp[2] = 2
                    //
                    // Those two ways are:
                    //   "1","1"  -> "aa"
                    //   "11"     -> "k"
                    dp[i] += dp[i - 2];
                }
            }

            // After the loop finishes, dp[n] contains the number of ways
            // to decode the entire string.
            //
            // Example:
            //   s = "111"
            //   dp[3] = 3
            //
            // Those 3 decodings are:
            //   "1","1","1" -> "aaa"
            //   "11","1"    -> "ka"
            //   "1","11"    -> "ak"
            return dp[n];
        }

        int charToNumber(char c)
        {
            if (c >= 'A' && c <= 'Z')
                return c - 'A' + 1;
            if (c >= 'a' && c <= 'z')
                return c - 'a' + 1;
            return -1; // not a letter
        }

        char numberToChar_uppercase(int n)
        {
            return 'A' + (n - 1);
        }

        char numberToChar_lowercase(int n){
            return 'a' + (n-1);
        }

        void Map_Alphabet(){
            for(int i =1; i<=26;i++){
                alphabet.push_back(numberToChar_uppercase(i));
            }
            //alphabet.push_back('#');
            //for(int i=1; i<=26;i++){
            //    alphabet.push_back(numberToChar_lowercase(i));
            //}

        };

        void printAlphabet(){
            for(char alpha : alphabet){
                std::cout<<alpha<<" ";
            }
        };

        std::vector<char> getAlphabet(){
            return alphabet;
        };

    private:

        std::vector<char> alphabet;

};