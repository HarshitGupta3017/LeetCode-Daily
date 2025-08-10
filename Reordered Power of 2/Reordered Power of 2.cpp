// Solution for Reordered Power of 2 in CPP

class Solution {
public:
    // Helper function: returns a "digit frequency signature" for a number
    // Instead of storing the digits directly, we represent each digit count
    // as a unique place value in base-10 encoding.
    // Example:
    //   128 -> 1 at position 1, 1 at position 2, 1 at position 8
    //   This produces a sum like 10^1 + 10^2 + 10^8
    int getDigitSignature(int number) {
        int signature = 0;
        while (number > 0) {
            int digit = number % 10;           // Extract last digit
            signature += pow(10, digit);       // Increment frequency position
            number /= 10;                      // Remove last digit
        }
        return signature;
    }

    bool reorderedPowerOf2(int n) {
        // Get the digit signature of the given number
        int originalSignature = getDigitSignature(n);

        // We only need to check powers of 2 up to 2^29 (~5e8)
        // because 2^30 > 10^9 (max limit for n)
        for (int power = 0; power <= 29; power++) {
            int powerOfTwo = 1 << power; // Compute 2^power

            // Compare digit signatures:
            // If they match, n can be reordered to form this power of two
            if (originalSignature == getDigitSignature(powerOfTwo)) {
                return true;
            }
        }
        return false; // No match found
    }
};
