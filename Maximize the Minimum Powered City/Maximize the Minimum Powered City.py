# Solution for Maximize the Minimum Powered City in PY

class Solution:
    # 🔹 Helper to check if we can achieve at least target power everywhere
    def canAchieveTarget(self, target: int, diff: List[int], r: int, k: int, n: int) -> bool:
        current = 0
        diff_copy = diff[:]  # copy so we don’t mutate the original

        for i in range(n):
            current += diff_copy[i]

            if current < target:
                needed = target - current

                if needed > k:
                    return False  # not enough extra stations available

                k -= needed
                current += needed

                # Cancel influence after (i + 2*r)
                if i + 2 * r + 1 < n:
                    diff_copy[i + 2 * r + 1] -= needed

        return True

    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        n = len(stations)
        diff = [0] * (n + 1)

        # Step 1️⃣: Build difference array from station influence
        for i in range(n):
            diff[max(0, i - r)] += stations[i]
            if i + r + 1 < n:
                diff[i + r + 1] -= stations[i]

        # Step 2️⃣: Define binary search range
        left, right = min(stations), sum(stations) + k
        best = 0

        # Step 3️⃣: Binary search to maximize the minimum achievable power
        while left <= right:
            mid = (left + right) // 2
            if self.canAchieveTarget(mid, diff, r, k, n):
                best = mid  # ✅ Feasible, go higher
                left = mid + 1
            else:
                right = mid - 1

        # Step 4️⃣: Return the best achievable minimum power
        return best
