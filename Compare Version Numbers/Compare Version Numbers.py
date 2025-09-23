# Solution for Compare Version Numbers in PY

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        # Split version strings by '.' and convert each part to integer
        v1 = [int(x) for x in version1.split('.')]
        v2 = [int(x) for x in version2.split('.')]

        # Compare up to the longer version length
        max_len = max(len(v1), len(v2))

        for i in range(max_len):
            num1 = v1[i] if i < len(v1) else 0
            num2 = v2[i] if i < len(v2) else 0

            if num1 < num2:
                return -1
            elif num1 > num2:
                return 1
        
        return 0
