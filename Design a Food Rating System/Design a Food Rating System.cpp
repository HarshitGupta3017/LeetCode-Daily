// Solution for Design a Food Rating System in CPP

class FoodRatings {
public:
    // Store the current rating for each food item
    unordered_map<string, int> foodToRating;
    
    // Store the cuisine type for each food item
    unordered_map<string, string> foodToCuisine;
    
    // Store a set of foods sorted by rating for each cuisine type
    unordered_map<string, set<pair<int, string>>> cuisineToFoods;

    // Constructor to initialize the system with food names, cuisines, and ratings
    FoodRatings(vector<string>& foodNames, vector<string>& foodCuisines, vector<int>& foodRatings) {
        int numFoods = foodNames.size(); // Get the number of foods
        
        // Iterate through each food item and set up the data structures
        for (int i = 0; i < numFoods; i++) {
            string food = foodNames[i]; // The food name
            string cuisine = foodCuisines[i]; // The cuisine type for this food
            int rating = foodRatings[i]; // The initial rating for the food
            
            // Map the food name to its rating
            foodToRating[food] = rating;
            
            // Map the food name to its cuisine type
            foodToCuisine[food] = cuisine;
            
            // Insert the food into the sorted set of foods for this cuisine
            // The foods are sorted by rating in descending order (so we use negative rating)
            cuisineToFoods[cuisine].insert({-rating, food});
        }
    }
    
    // Change the rating of a specific food
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food]; // Get the cuisine type for the food
        int oldRating = foodToRating[food]; // Get the current rating of the food
        
        // Update the food's rating
        foodToRating[food] = newRating;
        
        // Remove the old rating from the sorted set for the cuisine
        cuisineToFoods[cuisine].erase({-oldRating, food});
        
        // Insert the new rating into the sorted set for the cuisine
        cuisineToFoods[cuisine].insert({-newRating, food});
    }
    
    // Get the highest-rated food for a specific cuisine
    string highestRated(string cuisine) {
        // Return the food with the highest rating (the first element of the sorted set)
        // Since we stored the ratings as negative values, the highest rating is first
        return begin(cuisineToFoods[cuisine])->second;
    }
};
