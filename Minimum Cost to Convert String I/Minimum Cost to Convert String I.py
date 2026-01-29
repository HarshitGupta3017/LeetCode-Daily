# Solution for Minimum Cost to Convert String I in PY

class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: List[str],
        changed: List[str],
        cost: List[int]
    ) -> int:
        """
        Computes the minimum total cost to convert `source` into `target`.
        Returns -1 if any character conversion is impossible.
        """

        INF = 10**18  # A large value to represent "infinite" cost

        # min_cost[i][j] = minimum cost to convert character
        # chr(i + 'a') into chr(j + 'a')
        min_cost = [[INF] * 26 for _ in range(26)]

        # Step 1: Initialize direct transformation costs
        # For each allowed transformation original -> changed,
        # keep the minimum cost (duplicates may exist).
        for i in range(len(original)):
            from_char = ord(original[i]) - ord('a')
            to_char = ord(changed[i]) - ord('a')

            min_cost[from_char][to_char] = min(
                min_cost[from_char][to_char],
                cost[i]
            )

        # Step 2: Floyd–Warshall algorithm
        # Compute minimum cost between all pairs of characters
        # by allowing intermediate characters.
        for intermediate in range(26):
            for start in range(26):
                for end in range(26):
                    min_cost[start][end] = min(
                        min_cost[start][end],
                        min_cost[start][intermediate] +
                        min_cost[intermediate][end]
                    )

        total_cost = 0

        # Step 3: Compute total cost for source -> target conversion
        for i in range(len(source)):
            source_char = ord(source[i]) - ord('a')
            target_char = ord(target[i]) - ord('a')

            # No cost if characters are already the same
            if source_char == target_char:
                continue

            # If conversion is impossible, return -1
            if min_cost[source_char][target_char] == INF:
                return -1

            total_cost += min_cost[source_char][target_char]

        return total_cost
