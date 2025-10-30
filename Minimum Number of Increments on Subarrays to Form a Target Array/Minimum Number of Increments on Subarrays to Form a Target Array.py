# Solution for Minimum Number of Increments on Subarrays to Form a Target Array in PY

class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        # 'ops' will store the total minimum number of operations required
        ops = 0
        
        # 'prevHeight' keeps track of the previous element's value in 'target'
        # Initially, our 'initial' array starts with zeros, so we set it to 0.
        prevHeight = 0
        
        # Traverse through each number in the 'target' array
        for currHeight in target:
            
            # If the current height is greater than the previous height,
            # it means we need to perform extra increments to reach this new level.
            # Example: target = [1,3]
            # To go from 1 → 3, we need 2 more operations.
            if currHeight > prevHeight:
                ops += (currHeight - prevHeight) # Add the difference as new operations
            
            # If the current height is smaller or equal to the previous height,
            # we don't need to perform any operation here.
            # This is because the previous subarray increments already covered this range.

            # Update 'prevHeight' for the next iteration
            prevHeight = currHeight
        
        # The total number of required operations
        return ops
