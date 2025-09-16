# Solution for Replace Non-Coprime Numbers in Array in PY

class Solution:
    def replaceNonCoprimes(self, nums):
        final_array = []

        for num in nums:
            # Merge until coprime
            while final_array:
                last_num = final_array[-1]
                current_gcd = math.gcd(last_num, num)

                if current_gcd == 1:
                    break

                final_array.pop()
                lcm_value = last_num * num // current_gcd
                num = lcm_value
            final_array.append(num)

        return final_array
