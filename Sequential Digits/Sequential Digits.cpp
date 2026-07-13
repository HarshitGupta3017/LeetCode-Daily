// Solution for Sequential Digits in CPP

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // Seed the queue with single-digit numbers 1–8.
        // 9 is excluded because appending the next digit (10) is impossible —
        // sequential digits only go up to 9, so 9 has no valid child.
        queue<int> q;
        for (int digit = 1; digit <= 8; digit++)
            q.push(digit);

        vector<int> result;

        while (!q.empty()) {
            int num = q.front();
            q.pop();

            // Collect numbers that fall within the target range.
            if (num >= low && num <= high)
                result.push_back(num);

            // No point expanding further once we've exceeded the upper bound —
            // all children will be larger still.
            if (num > high) continue;

            // Extend the current number by appending the next sequential digit.
            // e.g. 123 → last digit is 3 → next number is 1234.
            int lastDigit = num % 10;
            if (lastDigit < 9)
                q.push(num * 10 + (lastDigit + 1));
        }

        // BFS expands numbers level by level (1-digit, then 2-digit, then 3-digit...),
        // and within each level seeds are pushed in ascending order (1,2,...,8),
        // so the output is naturally sorted without an explicit sort step.
        return result;
    }
};
