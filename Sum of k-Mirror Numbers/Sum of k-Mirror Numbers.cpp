// Solution for Sum of k-Mirror Numbers in CPP

class Solution {
public:
    // Convert a number to its base-k representation (in reverse order)
    string convertToBaseK(long long num, int k) {
        if (num == 0) return "0";
        string baseK = "";
        while (num > 0) {
            baseK += to_string(num % k);
            num /= k;
        }
        return baseK;
    }

    // Check if the given string is a palindrome
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    // Main function to find the sum of first n k-mirror numbers
    long long kMirror(int k, int n) {
        long long sum = 0;
        int length = 1;

        while (n > 0) {
            int halfLength = (length + 1) / 2;

            // Define numeric bounds to generate palindromes of current length
            long long min_num = pow(10, halfLength - 1);
            long long max_num = pow(10, halfLength) - 1;

            for (long long num = min_num; num <= max_num; ++num) {
                string leftHalf = to_string(num);
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());

                // Form the full palindrome
                string fullPalindrome = (length % 2 == 0)
                                        ? leftHalf + rightHalf
                                        : leftHalf + rightHalf.substr(1);

                long long palNum = stoll(fullPalindrome);

                // Check if the number is a palindrome in base-k too
                string baseK = convertToBaseK(palNum, k);
                if (isPalindrome(baseK)) {
                    sum += palNum;
                    n--;
                    if (n == 0) break;
                }
            }
            length++;
        }
        return sum;
    }
};
