# Solution for Block Placement Queries in PY

class SegmentTree:
    def __init__(self, size):
        self.n = size
        self.tree = [0] * (4 * size)

    def update(self, idx, val):
        self._update(idx, val, 0, 0, self.n - 1)

    def _update(self, idx, val, node, node_left, node_right):
        if node_left == node_right:
            self.tree[node] = val
            return

        mid = node_left + (node_right - node_left) // 2

        if idx <= mid:
            self._update(idx, val, 2 * node + 1, node_left, mid)
        else:
            self._update(idx, val, 2 * node + 2, mid + 1, node_right)

        self.tree[node] = max(
            self.tree[2 * node + 1],
            self.tree[2 * node + 2]
        )

    def query(self, left, right):
        return self._query(left, right, 0, 0, self.n - 1)

    def _query(self, left, right, node, node_left, node_right):
        if node_right < left or node_left > right:
            return 0

        if left <= node_left and node_right <= right:
            return self.tree[node]

        mid = node_left + (node_right - node_left) // 2

        return max(
            self._query(left, right, 2 * node + 1, node_left, mid),
            self._query(left, right, 2 * node + 2, mid + 1, node_right)
        )


class Solution:
    N = 50000

    def getResults(self, queries):
        seg_tree = SegmentTree(self.N)

        obstacles = SortedSet([0])
        results = []

        for q in queries:
            if q[0] == 1:
                x = q[1]

                idx = obstacles.bisect_right(x)
                left_obstacle = obstacles[idx - 1]

                right_obstacle = obstacles[idx] if idx < len(obstacles) else None

                seg_tree.update(x, x - left_obstacle)

                if right_obstacle is not None:
                    seg_tree.update(right_obstacle, right_obstacle - x)

                obstacles.add(x)

            else:
                x, sz = q[1], q[2]

                idx = obstacles.bisect_right(x)
                last_obstacle = obstacles[idx - 1]

                max_stored_gap = seg_tree.query(0, last_obstacle)
                trailing_gap = x - last_obstacle

                results.append(
                    max(max_stored_gap, trailing_gap) >= sz
                )

        return results
