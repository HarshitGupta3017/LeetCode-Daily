# Solution for Number of Steps to Reduce a Number in Binary Representation to One in PY

class Solution:
    def numSteps(self, s: str) -> int:
        
        length = len(s)               # Length of the binary string
        total_operations = 0          # Counts total steps required
        carry_from_addition = 0       # Simulates carry when we add 1
        
        # Traverse from right to left
        for index in range(length - 1, 0, -1):
            
            # Convert current character to integer
            current_bit = int(s[index])
            
            # Add carry
            effective_bit = current_bit + carry_from_addition
            
            # If even → divide by 2
            if effective_bit % 2 == 0:
                total_operations += 1
            # If odd → add 1 then divide by 2
            else:
                total_operations += 2
                carry_from_addition = 1
        
        # Add remaining carry if exists
        return total_operations + carry_from_addition
