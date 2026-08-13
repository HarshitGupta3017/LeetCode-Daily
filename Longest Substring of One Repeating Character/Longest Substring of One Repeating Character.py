# Solution for Longest Substring of One Repeating Character in PY

class Solution:

    class Node:
        def __init__(self, pre=0, suf=0, maxLen=0,
                     leftChar='\0', rightChar='\0'):
            self.pre = pre
            self.suf = suf
            self.maxLen = maxLen
            self.leftChar = leftChar
            self.rightChar = rightChar

    def merge(self, L, R, leftLen, rightLen):
        res = self.Node()

        res.leftChar = L.leftChar
        res.rightChar = R.rightChar

        res.pre = L.pre
        if L.pre == leftLen and L.rightChar == R.leftChar:
            res.pre = L.pre + R.pre

        res.suf = R.suf
        if R.suf == rightLen and L.rightChar == R.leftChar:
            res.suf = R.suf + L.suf

        res.maxLen = max(L.maxLen, R.maxLen)

        if L.rightChar == R.leftChar:
            res.maxLen = max(
                res.maxLen,
                L.suf + R.pre
            )

        return res

    def buildSegmentTree(self, i, l, r, s):
        if l == r:
            self.segTree[i] = self.Node(
                1, 1, 1,
                s[l],
                s[l]
            )
            return

        mid = l + (r - l) // 2

        self.buildSegmentTree(
            2 * i + 1, l, mid, s
        )

        self.buildSegmentTree(
            2 * i + 2, mid + 1, r, s
        )

        self.segTree[i] = self.merge(
            self.segTree[2 * i + 1],
            self.segTree[2 * i + 2],
            mid - l + 1,
            r - mid
        )

    def update(self, i, l, r, pos, ch):
        if l == r:
            self.segTree[i] = self.Node(
                1, 1, 1,
                ch,
                ch
            )
            return

        mid = l + (r - l) // 2

        if pos <= mid:
            self.update(
                2 * i + 1, l, mid, pos, ch
            )
        else:
            self.update(
                2 * i + 2, mid + 1, r, pos, ch
            )

        self.segTree[i] = self.merge(
            self.segTree[2 * i + 1],
            self.segTree[2 * i + 2],
            mid - l + 1,
            r - mid
        )

    def longestRepeating(
        self,
        s,
        queryCharacters,
        queryIndices
    ):
        self.n = len(s)

        self.segTree = [
            self.Node()
            for _ in range(4 * self.n)
        ]

        self.buildSegmentTree(
            0, 0, self.n - 1, s
        )

        result = []

        for i in range(len(queryIndices)):
            pos = queryIndices[i]
            ch = queryCharacters[i]

            self.update(
                0, 0, self.n - 1, pos, ch
            )

            result.append(
                self.segTree[0].maxLen
            )

        return result
