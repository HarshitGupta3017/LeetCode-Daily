// Solution for Coupon Code Validator in CPP
class Solution {
public:

    // ----------------------------------------------------
    // Checks whether a coupon code is valid:
    // - Must be non-empty
    // - Must contain only alphanumeric characters or '_'
    // ----------------------------------------------------
    bool isValidCode(string& couponCode) {
        if (couponCode.empty()) return false;

        for (char ch : couponCode) {
            // Allow letters, digits, and underscore only
            if (!isalnum(ch) && ch != '_') {
                return false;
            }
        }
        return true;
    }

    // ----------------------------------------------------
    // Checks whether the business line is one of
    // the allowed categories
    // ----------------------------------------------------
    bool isValidBusinessLine(string& category) {
        return (category == "electronics" ||
                category == "grocery" ||
                category == "pharmacy" ||
                category == "restaurant");
    }

    // ----------------------------------------------------
    // Main function:
    // Filters valid coupons and returns sorted result
    // ----------------------------------------------------
    vector<string> validateCoupons(
        vector<string>& code,
        vector<string>& businessLine,
        vector<bool>& isActive
    ) {

        // Map:
        //   key   → business line
        //   value → sorted collection of coupon codes
        map<string, multiset<string>> businessToCodes;

        // ------------------------------------------------
        // STEP 1: Filter valid coupons and group them
        // ------------------------------------------------
        for (int i = 0; i < code.size(); i++) {

            // Check all validity conditions
            if (isActive[i] &&
                isValidBusinessLine(businessLine[i]) &&
                isValidCode(code[i])) {

                // Insert code into its business category
                businessToCodes[businessLine[i]].insert(code[i]);
            }
        }

        // ------------------------------------------------
        // STEP 2: Build the final sorted result
        // - map ensures businessLine order
        // - multiset ensures lexicographical code order
        // ------------------------------------------------
        vector<string> validCoupons;

        for (const auto& entry : businessToCodes) {
            const multiset<string>& sortedCodes = entry.second;
            validCoupons.insert(
                validCoupons.end(),
                sortedCodes.begin(),
                sortedCodes.end()
            );
        }

        return validCoupons;
    }
};
