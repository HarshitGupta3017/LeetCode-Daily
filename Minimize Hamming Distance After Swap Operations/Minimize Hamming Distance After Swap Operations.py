# Solution for Minimize Hamming Distance After Swap Operations in PY

from collections import defaultdict, Counter

class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1] * n

    def find(self, node):
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])  # Path compression
        return self.parent[node]

    def unite(self, a, b):
        rootA = self.find(a)
        rootB = self.find(b)

        if rootA == rootB:
            return False

        if self.rank[rootA] < self.rank[rootB]:
            self.parent[rootA] = rootB
        elif self.rank[rootA] > self.rank[rootB]:
            self.parent[rootB] = rootA
        else:
            self.parent[rootB] = rootA
            self.rank[rootA] += 1

        return True


class Solution:
    def minimumHammingDistance(self, source, target, allowedSwaps):
        n = len(source)

        dsu = DSU(n)

        # Step 1: Union
        for a, b in allowedSwaps:
            dsu.unite(a, b)

        # Step 2: Group indices
        componentMap = defaultdict(list)

        for i in range(n):
            root = dsu.find(i)
            componentMap[root].append(i)

        result = 0

        # Step 3: Process components
        for indices in componentMap.values():
            freq = Counter(source[i] for i in indices)

            for i in indices:
                if freq[target[i]] > 0:
                    freq[target[i]] -= 1
                else:
                    result += 1

        return result
