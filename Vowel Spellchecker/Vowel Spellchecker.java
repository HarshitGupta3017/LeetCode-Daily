// Solution for Vowel Spellchecker in JAVA

class Solution {
    // Helper: Replace vowels with '*'
    private String maskVowels(String word) {
        StringBuilder sb = new StringBuilder();
        for (char ch : word.toCharArray()) {
            if ("aeiou".indexOf(ch) != -1) {
                sb.append('*');
            } else {
                sb.append(ch);
            }
        }
        return sb.toString();
    }

    public String[] spellchecker(String[] wordlist, String[] queries) {
        // Exact word set
        Set<String> exactMatch = new HashSet<>();

        // Case-insensitive and vowel-insensitive maps
        Map<String, String> caseInsensitiveMatch = new HashMap<>();
        Map<String, String> vowelInsensitiveMatch = new HashMap<>();

        // Preprocess wordlist
        for (String word : wordlist) {
            exactMatch.add(word);

            String lowerWord = word.toLowerCase();

            caseInsensitiveMatch.putIfAbsent(lowerWord, word);

            String vowelMasked = maskVowels(lowerWord);
            vowelInsensitiveMatch.putIfAbsent(vowelMasked, word);
        }

        String[] result = new String[queries.length];

        // Process each query
        for (int i = 0; i < queries.length; i++) {
            String query = queries[i];

            if (exactMatch.contains(query)) {
                result[i] = query;
                continue;
            }

            String lowerQuery = query.toLowerCase();
            if (caseInsensitiveMatch.containsKey(lowerQuery)) {
                result[i] = caseInsensitiveMatch.get(lowerQuery);
                continue;
            }

            String vowelMaskedQuery = maskVowels(lowerQuery);
            if (vowelInsensitiveMatch.containsKey(vowelMaskedQuery)) {
                result[i] = vowelInsensitiveMatch.get(vowelMaskedQuery);
                continue;
            }

            result[i] = "";
        }

        return result;
    }
}
