# Solution for Number of People Aware of a Secret in PY

class Solution:
    MOD = 10**9 + 7

    def countNewPeople(self, day: int, delay: int, forget: int, memo: list) -> int:
        if day == 1:
            return 1  # Base case: Day 1 → 1 person knows the secret

        if memo[day] != -1:
            return memo[day]  # Already computed

        ways = 0
        # Loop through possible "starting days"
        for d in range(day - forget + 1, day - delay + 1):
            if d > 0:
                ways = (ways + self.countNewPeople(d, delay, forget, memo)) % self.MOD

        memo[day] = ways
        return ways

    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        memo = [-1] * (n + 1)
        total = 0

        # Only people who haven't forgotten remain in the last window
        for day in range(n - forget + 1, n + 1):
            if day > 0:
                total = (total + self.countNewPeople(day, delay, forget, memo)) % self.MOD

        return total
