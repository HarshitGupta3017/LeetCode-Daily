// Solution for Total Characters in String After Transformations II in CPP

class Solution {
public:

    using Matrix = vector<vector<int>>;
    const int MOD = 1000000007;

    Matrix matrixMultiplication(Matrix& A, Matrix& B) {
        Matrix C(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
                }
            }
        }
        return C;
    }

    Matrix matrixExponentiation(Matrix& base, int exponent) {
        if (exponent == 0) {
            Matrix I(26, vector<int>(26, 0));
            for (int i = 0; i < 26; i++) {
                I[i][i] = 1;
            }
            return I;
        }
        Matrix half = matrixExponentiation(base, exponent / 2);
        Matrix result = matrixMultiplication(half, half);
        if (exponent % 2 == 1) {
            result = matrixMultiplication(result, base);
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Final freq state = T^t * initial freq state
        // initial freq
        vector<int> freq(26, 0);
        for (const auto& ch: s) {
            freq[ch - 'a']++;
        }

        // forming T matrix
        Matrix T(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int add = 1; add <= nums[i]; add++) {
                T[(i + add) % 26][i]++;
            }
        }

        // find T^t
        Matrix result = matrixExponentiation(T, t);
        
        vector<int> finalFreq(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                finalFreq[i] = (finalFreq[i] + (1LL * result[i][j] * freq[j]) % MOD) % MOD;
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + finalFreq[i]) % MOD;
        }
        return ans;
    }
};
