// Solution for Find Most Frequent Vowel and Consonant in CPP

class Solution {
public:
    int maxFreqSum(string s) {
        int maxConsonantFreq = 0; // highest frequency of consonants
        int maxVowelFreq = 0;     // highest frequency of vowels
        int frequency[26] = {0};  // frequency of each character 'a' to 'z'

        for (char ch : s) {
            frequency[ch - 'a']++; // update count of this character

            // Check if it's a vowel
            if (string("aeiou").find(ch) != string::npos) {
                maxVowelFreq = max(maxVowelFreq, frequency[ch - 'a']);
            } 
            // Otherwise, it's a consonant
            else {
                maxConsonantFreq = max(maxConsonantFreq, frequency[ch - 'a']);
            }
        }

        // Return sum of max vowel freq + max consonant freq
        return maxConsonantFreq + maxVowelFreq;
    }
};
