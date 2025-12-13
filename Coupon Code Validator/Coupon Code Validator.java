// Solution for Coupon Code Validator in JAVA

class Solution {

    // ----------------------------------------------------
    // Checks whether a coupon code is valid:
    // - Must be non-empty
    // - Must contain only alphanumeric characters or '_'
    // ----------------------------------------------------
    private boolean isValidCode(String couponCode) {
        if (couponCode == null || couponCode.isEmpty()) {
            return false;
        }

        for (char ch : couponCode.toCharArray()) {
            if (!Character.isLetterOrDigit(ch) && ch != '_') {
                return false;
            }
        }
        return true;
    }

    // ----------------------------------------------------
    // Checks whether the business line is one of
    // the allowed categories
    // ----------------------------------------------------
    private boolean isValidBusinessLine(String category) {
        return (category.equals("electronics") ||
                category.equals("grocery") ||
                category.equals("pharmacy") ||
                category.equals("restaurant"));
    }

    // ----------------------------------------------------
    // Main function:
    // Filters valid coupons and returns sorted result
    // ----------------------------------------------------
    public List<String> validateCoupons(
        String[] code,
        String[] businessLine,
        boolean[] isActive
    ) {

        // Map:
        //   key   → business line
        //   value → modifiable List of coupon codes (to allow duplicates)
        // TreeMap ensures businessLine keys are iterated in natural (alphabetical) order
        Map<String, List<String>> businessToCodes = new TreeMap<>();

        // ------------------------------------------------
        // STEP 1: Filter valid coupons and group them
        // ------------------------------------------------
        for (int i = 0; i < code.length; i++) {

            if (code[i] != null && businessLine[i] != null &&
                isActive[i] &&
                isValidBusinessLine(businessLine[i]) &&
                isValidCode(code[i])) {

                // Ensure the list is initialized for this business line
                businessToCodes.putIfAbsent(businessLine[i], new ArrayList<>());

                // Add code to the list (duplicates are allowed)
                businessToCodes.get(businessLine[i]).add(code[i]);
            }
        }

        // ------------------------------------------------
        // STEP 2: Build the final sorted result
        // - TreeMap ensures businessLine order (electronics, pharmacy, restaurant)
        // - Sort each list manually to ensure lexicographical code order within category
        // ------------------------------------------------
        List<String> validCoupons = new ArrayList<>();

        for (Map.Entry<String, List<String>> entry : businessToCodes.entrySet()) {
            List<String> codesInLine = entry.getValue();
            // Sort the codes within the category before adding to the final list
            Collections.sort(codesInLine);
            validCoupons.addAll(codesInLine);
        }

        return validCoupons;
    }
}
