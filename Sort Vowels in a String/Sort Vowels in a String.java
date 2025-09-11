// Solution for Sort Vowels in a String in JAVA

class Solution {
    // Helper method to check if a character is a vowel
    private boolean isVowel(char ch) {
        char lower = Character.toLowerCase(ch);
        return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
    }

    public String sortVowels(String s) {
        // Step 1: Count frequency of each vowel
        Map<Character, Integer> vowelFrequency = new HashMap<>();
        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) {
                vowelFrequency.put(ch, vowelFrequency.getOrDefault(ch, 0) + 1);
            }
        }

        // Step 2: Sorted vowel order (uppercase first, then lowercase)
        String sortedVowelOrder = "AEIOUaeiou";

        // Step 3: Replace vowels in the string with sorted vowels
        StringBuilder result = new StringBuilder(s);
        int vowelIndex = 0;

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);
            if (isVowel(currentChar)) {
                // Find next available vowel
                while (vowelIndex < sortedVowelOrder.length() &&
                       vowelFrequency.getOrDefault(sortedVowelOrder.charAt(vowelIndex), 0) == 0) {
                    vowelIndex++;
                }
                char replacement = sortedVowelOrder.charAt(vowelIndex);
                result.setCharAt(i, replacement);  
                vowelFrequency.put(replacement, vowelFrequency.get(replacement) - 1);
            }
        }
        return result.toString();
    }
}
