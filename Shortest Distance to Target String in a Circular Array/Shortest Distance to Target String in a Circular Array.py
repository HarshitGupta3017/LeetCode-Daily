# Solution for Shortest Distance to Target String in a Circular Array in PY

class Solution:
    def closestTarget(self, words, target, startIndex):
        
        total_words = len(words)
        minimum_steps = float('inf')

        # Traverse all positions to find occurrences of target
        for current_index in range(total_words):

            # Check if current word matches target
            if words[current_index] == target:

                # Linear distance (direct movement)
                linear_distance = abs(current_index - startIndex)

                # Circular distance (wrap-around movement)
                circular_distance = total_words - linear_distance

                # Choose the minimum of both paths
                best_distance = min(linear_distance, circular_distance)

                # Update global minimum
                minimum_steps = min(minimum_steps, best_distance)

        # If target was never found, return -1
        return -1 if minimum_steps == float('inf') else minimum_steps
