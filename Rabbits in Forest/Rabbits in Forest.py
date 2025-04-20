# Solution for Rabbits in Forest in PY

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        count = Counter(answers)
        result = 0
        for k, freq in count.items():
            group_size = k + 1
            groups = math.ceil(freq / group_size)
            result += groups * group_size
        return result
