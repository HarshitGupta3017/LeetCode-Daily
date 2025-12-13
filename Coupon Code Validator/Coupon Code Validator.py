# Solution for Coupon Code Validator in PY

from typing import List
from collections import defaultdict

class Solution:

    # ----------------------------------------------------
    # Checks whether a coupon code is valid
    # ----------------------------------------------------
    def isValidCode(self, couponCode: str) -> bool:
        if not couponCode:
            return False
        for ch in couponCode:
            if not (ch.isalnum() or ch == '_'):
                return False
        return True

    # ----------------------------------------------------
    # Checks whether the business line is valid
    # ----------------------------------------------------
    def isValidBusinessLine(self, category: str) -> bool:
        return category in {
            "electronics",
            "grocery",
            "pharmacy",
            "restaurant"
        }

    # ----------------------------------------------------
    # Main function
    # ----------------------------------------------------
    def validateCoupons(
        self,
        code: List[str],
        businessLine: List[str],
        isActive: List[bool]
    ) -> List[str]:

        businessToCodes = defaultdict(list)

        # STEP 1: Filter valid coupons
        for i in range(len(code)):
            if (isActive[i] and
                self.isValidBusinessLine(businessLine[i]) and
                self.isValidCode(code[i])):

                businessToCodes[businessLine[i]].append(code[i])

        # STEP 2: Sort by business line and coupon code
        result = []
        for category in sorted(businessToCodes.keys()):
            result.extend(sorted(businessToCodes[category]))

        return result
