# Solution for Sort Matrix by Diagonals in PY

class Solution:
    def sortMatrix(self, grid):
        n = len(grid)
        
        # Using defaultdict to collect elements by diagonal key (i - j)
        bottom_left_diags = defaultdict(list)
        top_right_diags = defaultdict(list)
        
        # Group elements by diagonals
        for i in range(n):
            for j in range(n):
                if i >= j:
                    bottom_left_diags[i - j].append(grid[i][j])
                else:
                    top_right_diags[i - j].append(grid[i][j])
        
        # Sort diagonals for bottom-left triangle (non-increasing order)
        for key in bottom_left_diags:
            bottom_left_diags[key].sort()
        
        # Sort diagonals for top-right triangle (non-decreasing order)
        for key in top_right_diags:
            top_right_diags[key].sort(reverse=True)
        
        # Rebuild the matrix by popping from sorted diagonals
        for i in range(n):
            for j in range(n):
                if i >= j:
                    grid[i][j] = bottom_left_diags[i - j].pop()
                else:
                    grid[i][j] = top_right_diags[i - j].pop()
        
        return grid
