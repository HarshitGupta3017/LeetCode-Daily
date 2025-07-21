// Solution for Delete Characters to Make Fancy String in CPP

class Solution {
public:
    // Function to make a fancy string by removing extra consecutive characters
    string makeFancyString(string s) {
        // This will store the final fancy version of the input string
        string fancyString = "";

        // Loop through each character of the input string
        for (int i = 0; i < s.size(); i++) {
            int n = fancyString.size();  // Get the current size of the fancy string

            /*
             * Check if the last two characters of the fancyString
             * are the same as the current character s[i].
             * If yes, it means adding s[i] will create three identical characters in a row.
             * We skip adding this character to prevent the "three-in-a-row" pattern.
             */
            if (n >= 2 && fancyString[n - 1] == s[i] && fancyString[n - 2] == s[i]) {
                continue;  // Skip adding s[i] to fancyString
            }

            // If the above condition is false, it's safe to add the character
            fancyString.push_back(s[i]);
        }

        // Return the final processed string which is now "fancy"
        return fancyString;
    }
};
