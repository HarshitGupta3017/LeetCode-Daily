class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num);
        for (int i = 0; i < digits.length(); i++) {
            int maxdigit = digits[i];
            int maxidx = i;
            for (int j = i + 1; j < digits.length(); j++) {
                if (digits[j] >= maxdigit) {
                    maxdigit = digits[j];
                    maxidx = j;
                }
            }
            if (maxdigit > digits[i]) {
                swap(digits[i], digits[maxidx]);
                break;
            }
        }
        return stoi(digits);
    }
};
