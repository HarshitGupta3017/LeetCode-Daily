// Solution for Max Difference You Can Get From Changing an Integer in CPP

class Solution {
public:
    int maxDiff(int num) {
        string maxStr = to_string(num); // Used for maximizing the number
        string minStr = maxStr;         // Used for minimizing the number

        // ----------- Step 1: Maximize the number -----------
        // Replace the first digit (that is not '9') with '9' throughout
        int firstNotNineIndex = maxStr.find_first_not_of('9');
        if (firstNotNineIndex != string::npos) {
            char toReplace = maxStr[firstNotNineIndex];
            // Replace all occurrences of this digit with '9'
            replace(begin(maxStr), end(maxStr), toReplace, '9');
        }

        // ----------- Step 2: Minimize the number -----------
        for (int i = 0; i < minStr.length(); i++) {
            char currentDigit = minStr[i];

            // Case 1: Change first digit (non-'1') to '1' to avoid leading zero
            if (i == 0 && currentDigit != '1') {
                replace(begin(minStr), end(minStr), currentDigit, '1');
                break;

            // Case 2: Change any other digit (non-'0' and not same as first digit) to '0'
            } else if (i > 0 && currentDigit != '0' && currentDigit != minStr[0]) {
                replace(begin(minStr), end(minStr), currentDigit, '0');
                break;
            }
        }

        // ----------- Step 3: Return difference -----------
        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);
        return maxNum - minNum;
    }
};
