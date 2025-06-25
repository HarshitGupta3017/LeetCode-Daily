# Solution for Kth Smallest Product of Two Sorted Arrays in PY

class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        def countProductsLessEqual(nums1, nums2, midProd):
            count = 0
            m = len(nums2)
            for a in nums1:
                if a >= 0:
                    left, right = 0, m - 1
                    validRight = -1
                    while left <= right:
                        mid = (left + right) // 2
                        product = a * nums2[mid]
                        if product <= midProd:
                            validRight = mid
                            left = mid + 1
                        else:
                            right = mid - 1
                    count += (validRight + 1)
                else:
                    left, right = 0, m - 1
                    validLeft = m
                    while left <= right:
                        mid = (left + right) // 2
                        product = a * nums2[mid]
                        if product <= midProd:
                            validLeft = mid
                            right = mid - 1
                        else:
                            left = mid + 1
                    count += (m - validLeft)
            return count

        low, high = -10**10, 10**10
        result = 0

        while low <= high:
            mid = (low + high) // 2
            cnt = countProductsLessEqual(nums1, nums2, mid)
            if cnt >= k:
                result = mid
                high = mid - 1
            else:
                low = mid + 1

        return result
