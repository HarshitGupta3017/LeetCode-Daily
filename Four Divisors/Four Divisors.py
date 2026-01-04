# Solution for Four Divisors in PY

class Solution:
    # Returns sum of divisors if num has exactly 4 divisors, else returns 0
    def getFourDivisorSum(self, num: int) -> int:
        divisor_count = 0
        divisor_sum = 0

        factor = 1
        while factor * factor <= num:
            if num % factor == 0:
                paired_factor = num // factor

                # Perfect square divisor
                if factor == paired_factor:
                    divisor_count += 1
                    divisor_sum += factor
                else:
                    divisor_count += 2
                    divisor_sum += factor + paired_factor

            # Early exit if more than 4 divisors
            if divisor_count > 4:
                return 0

            factor += 1

        return divisor_sum if divisor_count == 4 else 0

    def sumFourDivisors(self, nums):
        total_sum = 0

        for num in nums:
            total_sum += self.getFourDivisorSum(num)

        return total_sum
