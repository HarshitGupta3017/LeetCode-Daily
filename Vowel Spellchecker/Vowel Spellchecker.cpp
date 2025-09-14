// Solution for Vowel Spellchecker in CPP

class Solution {
public:
    // Helper: Replace all vowels with '*' for vowel-insensitive comparison
    string maskVowels(string word) {
        for (char &ch : word) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                ch = '*';
            }
        }
        return word;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // Exact word set (case-sensitive match)
        unordered_set<string> exactMatch;

        // Maps for case-insensitive and vowel-error-insensitive matches
        unordered_map<string, string> caseInsensitiveMatch;
        unordered_map<string, string> vowelInsensitiveMatch;

        // Preprocess the wordlist
        for (string word : wordlist) {
            exactMatch.insert(word);

            // Case-insensitive key (lowercase version)
            string lowerWord = word;
            transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

            // Store the first occurrence for capitalization-insensitive matches
            if (!caseInsensitiveMatch.count(lowerWord)) {
                caseInsensitiveMatch[lowerWord] = word;
            }

            // Vowel-masked version for vowel error handling
            string vowelMasked = maskVowels(lowerWord);
            if (!vowelInsensitiveMatch.count(vowelMasked)) {
                vowelInsensitiveMatch[vowelMasked] = word;
            }
        }

        vector<string> result;

        // Process each query
        for (string query : queries) {
            // Rule 1: Exact match (case-sensitive)
            if (exactMatch.count(query)) {
                result.push_back(query);
                continue;
            }

            // Rule 2: Case-insensitive match
            string lowerQuery = query;
            transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);
            if (caseInsensitiveMatch.count(lowerQuery)) {
                result.push_back(caseInsensitiveMatch[lowerQuery]);
                continue;
            }

            // Rule 3: Vowel-error-insensitive match
            string vowelMaskedQuery = maskVowels(lowerQuery);
            if (vowelInsensitiveMatch.count(vowelMaskedQuery)) {
                result.push_back(vowelInsensitiveMatch[vowelMaskedQuery]);
                continue;
            }

            // Rule 4: No match found
            result.push_back("");
        }

        return result;
    }
};
