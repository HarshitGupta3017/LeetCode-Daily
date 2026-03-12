# Solution for Maximize Spanning Tree Stability with Upgrades in PY

class DSU:

    def __init__(self, n):

        self.parent = list(range(n))
        self.rankValue = [1] * n

    def findParent(self, node):

        if self.parent[node] != node:
            self.parent[node] = self.findParent(self.parent[node])

        return self.parent[node]

    def unite(self, nodeA, nodeB):

        rootA = self.findParent(nodeA)
        rootB = self.findParent(nodeB)

        if rootA == rootB:
            return False

        if self.rankValue[rootA] < self.rankValue[rootB]:
            self.parent[rootA] = rootB
        elif self.rankValue[rootA] > self.rankValue[rootB]:
            self.parent[rootB] = rootA
        else:
            self.parent[rootB] = rootA
            self.rankValue[rootA] += 1

        return True


class Solution:

    def canBuildStableTree(
        self,
        totalNodes,
        edges,
        upgradesAvailable,
        targetStability
    ):

        dsu = DSU(totalNodes)

        upgradeEligibleEdges = []

        for edge in edges:

            nodeU, nodeV, strength, mustInclude = edge

            if mustInclude == 1:

                if strength < targetStability:
                    return False

                dsu.unite(nodeU, nodeV)

            else:

                if strength >= targetStability:
                    dsu.unite(nodeU, nodeV)

                elif 2 * strength >= targetStability:
                    upgradeEligibleEdges.append((nodeU, nodeV))

        for nodeU, nodeV in upgradeEligibleEdges:

            if dsu.findParent(nodeU) != dsu.findParent(nodeV):

                if upgradesAvailable == 0:
                    return False

                dsu.unite(nodeU, nodeV)
                upgradesAvailable -= 1

        rootComponent = dsu.findParent(0)

        for node in range(1, totalNodes):
            if dsu.findParent(node) != rootComponent:
                return False

        return True


    def maxStability(self, n, edges, k):

        validationDSU = DSU(n)

        bestStability = -1

        leftBound = float('inf')
        rightBound = float('-inf')

        for nodeU, nodeV, strength, mustInclude in edges:

            if mustInclude == 1:

                if validationDSU.findParent(nodeU) == validationDSU.findParent(nodeV):
                    return -1

                validationDSU.unite(nodeU, nodeV)

            leftBound = min(leftBound, strength)
            rightBound = max(rightBound, strength)

        rightBound *= 2

        while leftBound <= rightBound:

            midStability = (leftBound + rightBound) // 2

            if self.canBuildStableTree(n, edges, k, midStability):

                bestStability = midStability
                leftBound = midStability + 1

            else:
                rightBound = midStability - 1

        return bestStability
