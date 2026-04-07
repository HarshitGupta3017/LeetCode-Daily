// Solution for Walking Robot Simulation II in CPP

class Robot {
public:

    /*
        idx → current position in perimeter path
        hasMoved → to handle special initial direction case
        perimeter → stores the full boundary traversal

        Each entry:
        {x, y, direction_at_this_cell}
    */
    int idx = 0;
    bool hasMoved = false;
    vector<vector<int>> perimeter;

    Robot(int width, int height) {

        /*
        ============================================================
        STEP 1: Precompute FULL PERIMETER PATH
        ============================================================

        Instead of simulating each step repeatedly,
        we flatten the entire boundary into a circular array.

        Why valid?
        → Robot ALWAYS walks along boundary when it hits walls
        → Movement becomes cyclic
        */

        /*
        ------------------------------------------------------------
        1. Bottom row → move EAST
        (0,0) → (width-1,0)
        direction = 0 (East)
        ------------------------------------------------------------
        */
        for (int x = 0; x < width; x++) {
            perimeter.push_back({x, 0, 0});
        }

        /*
        ------------------------------------------------------------
        2. Right column → move NORTH
        (width-1,1) → (width-1,height-1)
        direction = 1 (North)
        ------------------------------------------------------------
        */
        for (int y = 1; y < height; y++) {
            perimeter.push_back({width - 1, y, 1});
        }

        /*
        ------------------------------------------------------------
        3. Top row → move WEST
        (width-2,height-1) → (0,height-1)
        direction = 2 (West)
        ------------------------------------------------------------
        */
        for (int x = width - 2; x >= 0; x--) {
            perimeter.push_back({x, height - 1, 2});
        }

        /*
        ------------------------------------------------------------
        4. Left column → move SOUTH
        (0,height-2) → (0,1)
        direction = 3 (South)
        ------------------------------------------------------------
        */
        for (int y = height - 2; y > 0; y--) {
            perimeter.push_back({0, y, 3});
        }

        /*
        IMPORTANT EDGE CASE:
        At starting point (0,0), after completing FULL cycle,
        robot faces SOUTH (not EAST)

        So we override direction at index 0
        */
        perimeter[0][2] = 3;
    }

    void step(int num) {

        hasMoved = true;

        /*
        ============================================================
        STEP 2: Move using modulo (cycle)
        ============================================================

        Since path is circular:
        → we just jump index

        No need to simulate each step → O(1)
        */
        idx = (idx + num) % perimeter.size();
    }

    vector<int> getPos() {

        /*
        Current position directly from precomputed path
        */
        return {perimeter[idx][0], perimeter[idx][1]};
    }

    string getDir() {

        /*
        SPECIAL CASE:
        Before any movement → robot is still at start
        and direction must be EAST (as per problem)
        */
        if (!hasMoved) return "East";

        vector<string> directions = {"East", "North", "West", "South"};

        /*
        Return direction stored at current index
        */
        return directions[perimeter[idx][2]];
    }
};
