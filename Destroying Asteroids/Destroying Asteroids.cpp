// Solution for Destroying Asteroids in CPP

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        // Always process asteroids from smallest to largest.
        //
        // Destroying a smaller asteroid first maximizes the planet's
        // growth as early as possible, making it easier to destroy
        // larger asteroids later.
        sort(asteroids.begin(), asteroids.end());

        // Mass can grow beyond the range of int after multiple absorptions.
        long long currentMass = mass;

        for (int asteroidMass : asteroids) {

            // If the planet cannot absorb the current asteroid,
            // no ordering among the remaining larger asteroids
            // can help, since the array is sorted.
            if (currentMass < asteroidMass) {
                return false;
            }

            // The asteroid is destroyed and its mass is added
            // to the planet's mass.
            currentMass += asteroidMass;
        }

        // Every asteroid was successfully absorbed.
        return true;
    }
};
