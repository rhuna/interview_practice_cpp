#include <iostream>
#include <vector>





class AlphaMap{
    public:
        AlphaMap(){};
        ~AlphaMap(){};


        //helper//
        int countDecodings(const std::string &s)
        {
            int n = s.size();
            std::vector<int> dp(n + 1, 0);

            dp[0] = 1; // empty string
            dp[1] = 1; // guaranteed decodable per problem statement

            for (int i = 2; i <= n; i++)
            {
                // Check one-digit decode
                if (s[i - 1] != '0')
                {
                    dp[i] += dp[i - 1];
                }

                // Check two-digit decode
                int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (twoDigit >= 10 && twoDigit <= 26)
                {
                    dp[i] += dp[i - 2];
                }
            }

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