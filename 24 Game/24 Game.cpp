// Solution for 24 Game in CPP

class Solution {
public:

    double epsilon = 1e-6; // precision ke liye tolerance (10^-6) use kar rahe hain

    // Recursive function jo check karega ki 24 ban sakta hai ya nahi
    bool canMake24(vector<double>& numbers) {
        // Base case: agar sirf 1 number bacha hai
        if (numbers.size() == 1) {
            // check karo ki kya yeh 24 ke bahut close hai
            return abs(numbers[0] - 24.0) <= epsilon;
        }

        // Har do alag numbers ka pair banate hain
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = 0; j < numbers.size(); j++) {
                if (i == j) continue; // same number ko pair me mat lo

                // Baaki numbers ek temp array me dalenge (sirf i aur j ko exclude karenge)
                vector<double> remaining;
                for (int k = 0; k < numbers.size(); k++) {
                    if (k != i && k != j) {
                        remaining.push_back(numbers[k]);
                    }
                }

                double num1 = numbers[i];
                double num2 = numbers[j];

                // Possible operations between num1 and num2
                vector<double> possibleResults = {
                    num1 + num2,   // addition
                    num1 - num2,   // subtraction (order matter karta hai)
                    num2 - num1,   // reverse subtraction
                    num1 * num2    // multiplication
                };

                // Division possible tabhi karenge jab denominator non-zero ho
                if (abs(num2) > 0.0) {
                    possibleResults.push_back(num1 / num2);
                }
                if (abs(num1) > 0.0) {
                    possibleResults.push_back(num2 / num1);
                }

                // Har ek result ke liye recursion lagao
                for (double val : possibleResults) {
                    remaining.push_back(val); // new value add karo
                    if (canMake24(remaining)) {
                        return true; // agar koi path se 24 bana toh true
                    }
                    remaining.pop_back(); // backtrack (last value hata do)
                }
            }
        }
        return false; // agar koi combination nahi mila toh false
    }

    bool judgePoint24(vector<int>& cards) {
        // Input ko double me convert karte hain taaki division sahi se handle ho
        vector<double> nums(cards.begin(), cards.end());
        return canMake24(nums);
    }
};
