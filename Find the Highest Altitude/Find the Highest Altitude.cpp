// Solution for Find the Highest Altitude in CPP

class Solution {
public:
   int largestAltitude(vector<int>& gain) {
       // The biker starts at altitude 0, which is a candidate for the highest point
       // in case all subsequent altitudes are negative — so we initialise peak to 0.
       int currentAltitude = 0;
       int peakAltitude    = 0;

       for (int g : gain) {
           currentAltitude += g;
           peakAltitude = max(peakAltitude, currentAltitude);
       }

       return peakAltitude;
   }
};
