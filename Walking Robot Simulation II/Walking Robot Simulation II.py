# Solution for Walking Robot Simulation II in PY

class Robot:

    def __init__(self, width: int, height: int):
        """
        idx → current position in perimeter path
        hasMoved → to handle initial direction case
        perimeter → stores {x, y, direction}
        """
        self.idx = 0
        self.hasMoved = False
        self.perimeter = []

        # 1. Bottom row → EAST (0)
        for x in range(width):
            self.perimeter.append([x, 0, 0])

        # 2. Right column → NORTH (1)
        for y in range(1, height):
            self.perimeter.append([width - 1, y, 1])

        # 3. Top row → WEST (2)
        for x in range(width - 2, -1, -1):
            self.perimeter.append([x, height - 1, 2])

        # 4. Left column → SOUTH (3)
        for y in range(height - 2, 0, -1):
            self.perimeter.append([0, y, 3])

        # Edge case: at (0,0) after full cycle → SOUTH
        self.perimeter[0][2] = 3

    def step(self, num: int) -> None:
        self.hasMoved = True

        # circular movement
        self.idx = (self.idx + num) % len(self.perimeter)

    def getPos(self) -> List[int]:
        return [self.perimeter[self.idx][0], self.perimeter[self.idx][1]]

    def getDir(self) -> str:
        if not self.hasMoved:
            return "East"

        directions = ["East", "North", "West", "South"]
        return directions[self.perimeter[self.idx][2]]
