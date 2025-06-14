// Solution for Maximum Difference by Remapping a Digit in CPP

class Solution {
public:
    int minMaxDifference(int num) {
        // Convert the number to a string to manipulate digits
        string strMax = to_string(num);
        string strMin = strMax;

        // ----------- Create maximum number -----------
        // Find first digit that is not '9' to replace it with '9'
        int idx = strMax.find_first_not_of('9');
        if (idx != string::npos) {
            char toReplace = strMax[idx];
            // Replace all occurrences of that digit with '9'
            replace(strMax.begin(), strMax.end(), toReplace, '9');
        }

        // ----------- Create minimum number -----------
        // Replace all occurrences of the first digit with '0'
        char firstDigit = strMin[0];
        replace(strMin.begin(), strMin.end(), firstDigit, '0');

        // Return the difference
        return stoi(strMax) - stoi(strMin);
    }
};
