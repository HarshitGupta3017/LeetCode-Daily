# Solution for Remove Methods From Project in PY

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        in_degree = [0] * n

        for caller, callee in invocations:
            adj[caller].append(callee)
            in_degree[callee] += 1

        suspicious = [False] * n
        queue = deque([k])
        suspicious[k] = True

        while queue:
            method = queue.popleft()

            for callee in adj[method]:
                in_degree[callee] -= 1

                if not suspicious[callee]:
                    suspicious[callee] = True
                    queue.append(callee)

        for method in range(n):
            if suspicious[method] and in_degree[method] > 0:
                return list(range(n))

        return [method for method in range(n) if not suspicious[method]]
