# Solution for Lexicographically Smallest Equivalent String in PY

class Solution:
    def findSmallestEquivalentChar(self, graph, current_char, visited):
        visited[ord(current_char) - ord('a')] = True
        smallest_char = current_char

        for neighbor in graph[ord(current_char) - ord('a')]:
            if not visited[ord(neighbor) - ord('a')]:
                candidate = self.findSmallestEquivalentChar(graph, neighbor, visited)
                if candidate < smallest_char:
                    smallest_char = candidate

        return smallest_char

    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        graph = [[] for _ in range(26)]

        for u, v in zip(s1, s2):
            graph[ord(u) - ord('a')].append(v)
            graph[ord(v) - ord('a')].append(u)

        result = []

        for ch in baseStr:
            visited = [False] * 26
            smallest = self.findSmallestEquivalentChar(graph, ch, visited)
            result.append(smallest)

        return ''.join(result)
