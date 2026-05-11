// Solution for Separate the Digits in an Array in CPP

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> separatedDigits;

        // Process each number in given order
        for (const int& number : nums) {

            // Convert number into string
            string numberString = to_string(number);

            // Extract each digit character
            for (char digitChar : numberString) {

                // Convert character -> integer digit
                separatedDigits.push_back(digitChar - '0');
            }
        }

        return separatedDigits;
    }
};
