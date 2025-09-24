# Solution for Fraction to Recurring Decimal in PY

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # Case 1: If numerator is 0
        if numerator == 0:
            return "0"

        result = []

        # Case 2: Handle negative result
        if (numerator * denominator) < 0:
            result.append("-")

        # Work with absolute values
        numerator, denominator = abs(numerator), abs(denominator)

        # Step 1: Integer part
        result.append(str(numerator // denominator))

        remainder = numerator % denominator

        # Exact division
        if remainder == 0:
            return "".join(result)

        result.append(".")

        # Map to track remainder → index
        mp = {}

        # Step 4: Long division
        while remainder != 0:
            if remainder in mp:
                # Insert "(" at repeating index
                result.insert(mp[remainder], "(")
                result.append(")")
                break

            mp[remainder] = len(result)

            remainder *= 10
            result.append(str(remainder // denominator))
            remainder %= denominator

        return "".join(result)
