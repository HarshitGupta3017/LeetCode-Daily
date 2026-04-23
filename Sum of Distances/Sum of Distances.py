# Solution for Sum of Distances in PY

class Solution:
    def distance(self, nums):
        n = len(nums)

        # Map value -> list of indices
        value_to_indices = defaultdict(list)

        for i, num in enumerate(nums):
            value_to_indices[num].append(i)

        result = [0] * n

        # Process each group
        for indices in value_to_indices.values():

            size = len(indices)

            prefix = [0] * size
            prefix[0] = indices[0]

            for i in range(1, size):
                prefix[i] = prefix[i - 1] + indices[i]

            for i in range(size):

                curr_index = indices[i]

                left = 0
                if i > 0:
                    left = i * curr_index - prefix[i - 1]

                right = 0
                if i < size - 1:
                    right_count = size - i - 1
                    right_sum = prefix[size - 1] - prefix[i]
                    right = right_sum - right_count * curr_index

                result[curr_index] = left + right

        return result
