// Solution for Destroying Asteroids in JAVA

class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {

        // Always process asteroids from smallest to largest.
        Arrays.sort(asteroids);

        // Mass can grow beyond the range of int.
        long currentMass = mass;

        for (int asteroidMass : asteroids) {

            // If the planet cannot absorb this asteroid,
            // it cannot absorb any larger one either.
            if (currentMass < asteroidMass) {
                return false;
            }

            // Absorb the asteroid and gain its mass.
            currentMass += asteroidMass;
        }

        return true;
    }
}
