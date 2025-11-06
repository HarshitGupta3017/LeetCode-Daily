# Solution for Power Grid Maintenance in PY

class Solution:
    def processQueries(self, totalStations: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        parent = list(range(totalStations + 1))
        rank = [0] * (totalStations + 1)

        # 🔹 Find with path compression
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        # 🔹 Union by rank
        def union(a, b):
            rootA, rootB = find(a), find(b)
            if rootA == rootB:
                return
            if rank[rootA] < rank[rootB]:
                parent[rootA] = rootB
            elif rank[rootA] > rank[rootB]:
                parent[rootB] = rootA
            else:
                parent[rootB] = rootA
                rank[rootA] += 1

        # Build components
        for u, v in connections:
            union(u, v)

        # Sets for each component
        component_stations = defaultdict(set)
        for station in range(1, totalStations + 1):
            root = find(station)
            component_stations[root].add(station)

        # Track online/offline
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
                    if component_stations[root]:
                        res.append(min(component_stations[root]))
                    else:
                        res.append(-1)
            elif t == 2:
                # 🔴 Take offline
                if is_online[station]:
                    is_online[station] = False
                    component_stations[root].discard(station)

        return res
