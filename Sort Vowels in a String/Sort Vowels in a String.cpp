// Solution for Sort Vowels in a String in CPP

class Solution {
public:
    string sortVowels(string s) {
        // Helper lambda to check if a character is a vowel
        auto isVowel = [](char ch) {
            char lowerChar = tolower(ch);  // Convert to lowercase for uniform comparison
            return (lowerChar == 'a' || lowerChar == 'e' ||
                    lowerChar == 'i' || lowerChar == 'o' ||
                    lowerChar == 'u');
        };

        // Step 1: Count frequency of each vowel (case-sensitive)
        unordered_map<char, int> vowelFrequency;
        for (char ch : s) {
            if (isVowel(ch)) {
                vowelFrequency[ch]++;
            }
        }

        // Step 2: Define vowels in sorted order (uppercase before lowercase)
        string sortedVowelOrder = "AEIOUaeiou";

        // Step 3: Replace vowels in the string with sorted vowels
        int vowelIndex = 0; // Pointer to current position in sortedVowelOrder
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                // Find the next available vowel from the frequency map
                while (vowelIndex < sortedVowelOrder.size() &&
                       vowelFrequency[sortedVowelOrder[vowelIndex]] == 0) {
                    vowelIndex++;
                }

                // Replace and decrement frequency
                s[i] = sortedVowelOrder[vowelIndex];
                vowelFrequency[sortedVowelOrder[vowelIndex]]--;
            }
        }

        return s; // Final string with vowels sorted
    }
};
