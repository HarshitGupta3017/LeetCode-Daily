# Solution for Sum of k-Mirror Numbers in PY

class Solution:
    def convertToBaseK(self, num: int, k: int) -> str:
        if num == 0:
            return "0"
        base_k = ""
        while num > 0:
            base_k += str(num % k)
            num //= k
        return base_k

    def isPalindrome(self, s: str) -> bool:
        return s == s[::-1]

    def kMirror(self, k: int, n: int) -> int:
        total_sum = 0
        length = 1

        while n > 0:
            half_len = (length + 1) // 2
            start = 10 ** (half_len - 1)
            end = 10 ** half_len

            for num in range(start, end):
                left = str(num)
                right = left[::-1]
                full_palindrome = left + right if length % 2 == 0 else left + right[1:]
                pal_num = int(full_palindrome)

                base_k = self.convertToBaseK(pal_num, k)
                if self.isPalindrome(base_k):
                    total_sum += pal_num
                    n -= 1
                    if n == 0:
                        break

            length += 1

        return total_sum
