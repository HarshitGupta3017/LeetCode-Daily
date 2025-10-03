# Solution for Trapping Rain Water II in PY

class Solution:
    def trapRainWater(self, heightMap):
        rows, cols = len(heightMap), len(heightMap[0])
        visited = [[False] * cols for _ in range(rows)]
        minHeap = []  # heap will store (height, row, col)

        # Step 1: Add boundary cells (left & right columns)
        for r in range(rows):
            for c in [0, cols - 1]:
                heapq.heappush(minHeap, (heightMap[r][c], r, c))
                visited[r][c] = True

        # Step 2: Add boundary cells (top & bottom rows)
        for c in range(cols):
            for r in [0, rows - 1]:
                heapq.heappush(minHeap, (heightMap[r][c], r, c))
                visited[r][c] = True

        trappedWater = 0
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        # Step 3: Process cells in increasing order of height
        while minHeap:
            height, r, c = heapq.heappop(minHeap)

            # Step 4: Explore neighbors
            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if 0 <= nr < rows and 0 <= nc < cols and not visited[nr][nc]:
                    trappedWater += max(0, height - heightMap[nr][nc])

                    # Push neighbor with effective boundary height
                    heapq.heappush(minHeap, (max(height, heightMap[nr][nc]), nr, nc))
                    visited[nr][nc] = True

        return trappedWater
