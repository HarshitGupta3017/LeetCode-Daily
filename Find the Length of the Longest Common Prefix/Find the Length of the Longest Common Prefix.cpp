// Solution for Find the Length of the Longest Common Prefix in CPP

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        // Store all possible prefixes from arr1
        unordered_set<int> prefixes;

        int longestPrefixLength = 0;

        // Generate prefixes for every number in arr1
        for (int& number : arr1) {

            while (!prefixes.count(number) && number > 0) {

                prefixes.insert(number);

                // Remove last digit to form next prefix
                number /= 10;
            }
        }

        // Check prefixes for numbers in arr2
        for (int& number : arr2) {

            // Keep removing digits until
            // a common prefix is found
            while (!prefixes.count(number) && number > 0) {

                number /= 10;
            }

            // Valid common prefix found
            if (number > 0) {

                longestPrefixLength = max(longestPrefixLength, (int)log10(number) + 1);
            }
        }

        return longestPrefixLength;
    }
};
