# Solution for Maximum Ice Cream Bars in PY

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:

        freq = [0] * (max(costs) + 1)

        for cost in costs:
            freq[cost] += 1

        count = 0

        for price in range(1, len(freq)):

            can_buy = min(freq[price], coins // price)

            count += can_buy
            coins -= can_buy * price

            if coins < price:
                break

        return count
