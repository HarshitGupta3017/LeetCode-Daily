// Solution for Sum Game in CPP

class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int half = n / 2;

        int leftDigitSum  = 0, rightDigitSum  = 0;
        int leftWildcards = 0, rightWildcards = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                (i < half ? leftWildcards : rightWildcards)++;
            } else {
                (i < half ? leftDigitSum : rightDigitSum) += num[i] - '0';
            }
        }

        // If the total number of wildcards is odd, one player must place a digit
        // with no matching counterpart on the other side — Alice can always break balance.
        if ((leftWildcards + rightWildcards) % 2 != 0) return true;

        // Bob's optimal strategy is to pair each wildcard he places on one side with
        // a wildcard on the other side using digits that cancel out (e.g. 0 and 9).
        // Each wildcard is worth 4.5 on average (9/2), so Bob can balance iff:
        //   leftDigitSum + leftWildcards * 4.5 == rightDigitSum + rightWildcards * 4.5
        // Multiply both sides by 2 to avoid fractions:
        //   2*leftDigitSum + 9*leftWildcards == 2*rightDigitSum + 9*rightWildcards
        // If this holds, Bob can always mirror Alice's moves to maintain balance.
        // If it doesn't, Alice exploits the imbalance and Bob can never recover.
        return (2 * leftDigitSum + 9 * leftWildcards) != (2 * rightDigitSum + 9 * rightWildcards);
    }
};
