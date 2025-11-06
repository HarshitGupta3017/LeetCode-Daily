# Solution for Power Grid Maintenance in PY

class Solution:
    def processQueries(self, totalStations, connections, queries):
        parent = list(range(totalStations + 1))
        rank = [0] * (totalStations + 1)

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(a, b):
            ra, rb = find(a), find(b)
            if ra == rb:
                return
            if rank[ra] < rank[rb]:
                parent[ra] = rb
            elif rank[ra] > rank[rb]:
                parent[rb] = ra
            else:
                parent[rb] = ra
                rank[ra] += 1

        # Build components
        for u, v in connections:
            union(u, v)

        # Build heaps for each component
        component_heap = defaultdict(list)
        for station in range(1, totalStations + 1):
            heapq.heappush(component_heap[find(station)], station)

        is_online = [True] * (totalStations + 1)
        res = []

        # Process queries
        for t, station in queries:
            root = find(station)

            if t == 1:
                # 🟢 Maintenance check
                if is_online[station]:
                    res.append(station)
                else:
                    # Pop offline stations from heap top (lazy removal)
                    while component_heap[root] and not is_online[component_heap[root][0]]:
                        heapq.heappop(component_heap[root])
                    res.append(component_heap[root][0] if component_heap[root] else -1)

            elif t == 2:
                # 🔴 Take offline
                if is_online[station]:
                    is_online[station] = False

        return res
