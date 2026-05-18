# Solution for Jump Game IV in PY

class Solution:
    def minJumps(self, arr: List[int]) -> int:

        total_elements = len(arr)

        # Store all indices corresponding to each value
        value_indices_map = defaultdict(list)

        for index, value in enumerate(arr):
            value_indices_map[value].append(index)

        # Standard BFS setup
        bfs_queue = deque([0])

        visited = [False] * total_elements
        visited[0] = True

        steps = 0

        while bfs_queue:

            current_level_size = len(bfs_queue)

            for _ in range(current_level_size):

                current_index = bfs_queue.popleft()

                # Reached last index
                if current_index == total_elements - 1:
                    return steps

                # Move to previous index
                if current_index - 1 >= 0 and not visited[current_index - 1]:
                    visited[current_index - 1] = True
                    bfs_queue.append(current_index - 1)

                # Move to next index
                if current_index + 1 < total_elements and not visited[current_index + 1]:
                    visited[current_index + 1] = True
                    bfs_queue.append(current_index + 1)

                # Jump to all indices having same value
                for next_index in value_indices_map[arr[current_index]]:

                    if not visited[next_index]:
                        visited[next_index] = True
                        bfs_queue.append(next_index)

                # Remove processed value group
                value_indices_map[arr[current_index]].clear()

            steps += 1

        return steps
