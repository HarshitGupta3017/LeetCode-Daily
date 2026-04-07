// Solution for Walking Robot Simulation II in JAVA

class Robot {

    /*
        idx → current position in perimeter path
        hasMoved → to handle special initial direction case
        perimeter → stores the full boundary traversal

        Each entry:
        {x, y, direction_at_this_cell}
    */
    int idx = 0;
    boolean hasMoved = false;
    List<int[]> perimeter = new ArrayList<>();

    public Robot(int width, int height) {

        /*
        1. Bottom row → EAST
        */
        for (int x = 0; x < width; x++) {
            perimeter.add(new int[]{x, 0, 0});
        }

        /*
        2. Right column → NORTH
        */
        for (int y = 1; y < height; y++) {
            perimeter.add(new int[]{width - 1, y, 1});
        }

        /*
        3. Top row → WEST
        */
        for (int x = width - 2; x >= 0; x--) {
            perimeter.add(new int[]{x, height - 1, 2});
        }

        /*
        4. Left column → SOUTH
        */
        for (int y = height - 2; y > 0; y--) {
            perimeter.add(new int[]{0, y, 3});
        }

        /*
        Edge case: after full cycle, direction at (0,0) is SOUTH
        */
        perimeter.get(0)[2] = 3;
    }

    public void step(int num) {
        hasMoved = true;

        /*
        Circular movement using modulo
        */
        idx = (idx + num) % perimeter.size();
    }

    public int[] getPos() {
        return new int[]{perimeter.get(idx)[0], perimeter.get(idx)[1]};
    }

    public String getDir() {

        /*
        Before any movement → EAST
        */
        if (!hasMoved) return "East";

        String[] directions = {"East", "North", "West", "South"};
        return directions[perimeter.get(idx)[2]];
    }
}
