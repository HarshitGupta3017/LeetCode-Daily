// Solution for Smallest Palindromic Rearrangement I in CPP

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int halfLen = n / 2;

        // Only the first half determines the lexicographic order of a palindrome,
        // since the second half is always a mirror of the first.
        // Sorting the first half gives the lexicographically smallest arrangement.
        sort(s.begin(), s.begin() + halfLen);

        // Mirror the sorted first half onto the second half.
        // The middle character (if n is odd) is untouched — it can be anything
        // and doesn't affect lexicographic order between valid palindromes.
        for (int i = 0; i < halfLen; i++)
            s[n - 1 - i] = s[i];

        return s;
    }
};
