# Solution for Maximum Total Subarray Value II in PY

class SegmentTree:
    def __init__(self, nums: List[int], is_min_tree: bool):
        self.is_min_tree = is_min_tree
        n = len(nums)
        self.tree = [0] * (4 * n)
        self.build(0, 0, n - 1, nums)

    def build(self, node: int, node_left: int, node_right: int, nums: List[int]):

        if node_left == node_right:
            self.tree[node] = nums[node_left]
            return

        mid = node_left + (node_right - node_left) // 2

        self.build(2 * node + 1, node_left, mid, nums)
        self.build(2 * node + 2, mid + 1, node_right, nums)

        if self.is_min_tree:
            self.tree[node] = min(
                self.tree[2 * node + 1],
                self.tree[2 * node + 2]
            )
        else:
            self.tree[node] = max(
                self.tree[2 * node + 1],
                self.tree[2 * node + 2]
            )

    def query(self, query_left: int, query_right: int, n: int) -> int:
        return self.query_range(query_left, query_right, 0, 0, n - 1)

    def query_range(self, query_left: int, query_right: int,
                    node: int, node_left: int,
                    node_right: int) -> int:

        if node_left > query_right or node_right < query_left:
            return float('inf') if self.is_min_tree else float('-inf')

        if node_left >= query_left and node_right <= query_right:
            return self.tree[node]

        mid = node_left + (node_right - node_left) // 2

        left_result = self.query_range(
            query_left, query_right,
            2 * node + 1, node_left, mid
        )

        right_result = self.query_range(
            query_left, query_right,
            2 * node + 2, mid + 1, node_right
        )

        return (
            min(left_result, right_result)
            if self.is_min_tree
            else max(left_result, right_result)
        )


class Solution:
    def subarray_value(self, l, r, min_st, max_st, n):
        return max_st.query(l, r, n) - min_st.query(l, r, n)

    def maxTotalValue(self, nums: List[int], k: int) -> int:
        n = len(nums)

        min_st = SegmentTree(nums, True)
        max_st = SegmentTree(nums, False)

        # max heap via negative values
        max_heap = []

        for l in range(n):
            value = self.subarray_value(
                l, n - 1,
                min_st, max_st, n
            )
            heapq.heappush(
                max_heap,
                (-value, l, n - 1)
            )

        total_value = 0

        while k > 0:
            neg_value, l, r = heapq.heappop(max_heap)
            value = -neg_value

            total_value += value

            if l <= r - 1:
                next_value = self.subarray_value(
                    l, r - 1,
                    min_st, max_st, n
                )

                heapq.heappush(
                    max_heap,
                    (-next_value, l, r - 1)
                )

            k -= 1

        return total_value
