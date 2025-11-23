# Solution for Greatest Sum Divisible by Three in PY

class Solution:
    def maxSumDivThree(self, nums):
        total_sum = 0

        rem1_min1 = float('inf')
        rem1_min2 = float('inf')

        rem2_min1 = float('inf')
        rem2_min2 = float('inf')

        # Step 1: Compute total sum + track smallest candidates
        for num in nums:
            total_sum += num
            rem = num % 3

            if rem == 1:
                if num < rem1_min1:
                    rem1_min2 = rem1_min1
                    rem1_min1 = num
                elif num < rem1_min2:
                    rem1_min2 = num

            elif rem == 2:
                if num < rem2_min1:
                    rem2_min2 = rem2_min1
                    rem2_min1 = num
                elif num < rem2_min2:
                    rem2_min2 = num

        # Step 2: Already divisible?
        if total_sum % 3 == 0:
            return total_sum

        best_removal = float('inf')

        # Step 3: sum % 3 == 1
        if total_sum % 3 == 1:
            best_removal = min(best_removal, rem1_min1)
            if rem2_min2 != float('inf'):
                best_removal = min(best_removal, rem2_min1 + rem2_min2)

        # Step 4: sum % 3 == 2
        else:
            best_removal = min(best_removal, rem2_min1)
            if rem1_min2 != float('inf'):
                best_removal = min(best_removal, rem1_min1 + rem1_min2)

        return total_sum - best_removal
