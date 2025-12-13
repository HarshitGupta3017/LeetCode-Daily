// Solution for Coupon Code Validator in JAVA

import java.util.*;

class Solution {

    // ----------------------------------------------------
    // Checks whether a coupon code is valid:
    // - Must be non-empty
    // - Must contain only alphanumeric characters or '_'
    // ----------------------------------------------------
    private boolean isValidCode(String couponCode) {
        if (couponCode == null || couponCode.isEmpty()) return false;

        for (char ch : couponCode.toCharArray()) {
            if (!Character.isLetterOrDigit(ch) && ch != '_') {
                return false;
            }
        }
        return true;
    }

    // ----------------------------------------------------
    // Checks whether the business line is valid
    // ----------------------------------------------------
    private boolean isValidBusinessLine(String category) {
        return category.equals("electronics") ||
               category.equals("grocery") ||
               category.equals("pharmacy") ||
               category.equals("restaurant");
    }

    // ----------------------------------------------------
    // Main function
    // ----------------------------------------------------
    public List<String> validateCoupons(String[] code,
                                        String[] businessLine,
                                        boolean[] isActive) {

        // TreeMap → keeps business lines sorted
        // TreeSet → keeps coupon codes sorted
        Map<String, TreeSet<String>> businessToCodes = new TreeMap<>();

        // STEP 1: Filter valid coupons
        for (int i = 0; i < code.length; i++) {
            if (isActive[i] &&
                isValidBusinessLine(businessLine[i]) &&
                isValidCode(code[i])) {

                businessToCodes
                    .computeIfAbsent(businessLine[i], k -> new TreeSet<>())
                    .add(code[i]);
            }
        }

        // STEP 2: Build final sorted result
        List<String> result = new ArrayList<>();
        for (TreeSet<String> codes : businessToCodes.values()) {
            result.addAll(codes);
        }

        return result;
    }
}
