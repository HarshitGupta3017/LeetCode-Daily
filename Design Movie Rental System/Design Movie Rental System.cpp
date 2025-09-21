// Solution for Design Movie Rental System in CPP

class MovieRentingSystem {
public:
    // For each movie → set of (price, shop) storing available unrented copies
    unordered_map<int, set<pair<int, int>>> availableMovies;

    // For each movie → map of (shop → price) for quick lookup of its price
    unordered_map<int, unordered_map<int, int>> moviePriceMap;

    // All currently rented movies → (price, shop, movie) sorted as required
    set<tuple<int, int, int>> rentedMovies;

    // Constructor: initialize shop/movie/price data
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            availableMovies[movie].insert({price, shop});
            moviePriceMap[movie][shop] = price;
        }
    }

    // Search: return up to 5 cheapest shops that have this movie unrented
    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;

        if (availableMovies.count(movie)) {
            for (const auto& [price, shop] : availableMovies[movie]) {
                result.push_back(shop);
                if (++count == 5) break;
            }
        }

        return result;
    }

    // Rent: mark a movie from a given shop as rented
    void rent(int shop, int movie) {
        int price = moviePriceMap[movie][shop];

        // Remove from available pool
        availableMovies[movie].erase({price, shop});

        // Add to rented pool
        rentedMovies.insert({price, shop, movie});
    }

    // Drop: return a rented movie back to available
    void drop(int shop, int movie) {
        int price = moviePriceMap[movie][shop];

        // Add back to available pool
        availableMovies[movie].insert({price, shop});

        // Remove from rented pool
        rentedMovies.erase({price, shop, movie});
    }

    // Report: return up to 5 cheapest currently rented movies
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;

        for (const auto& [price, shop, movie] : rentedMovies) {
            result.push_back({shop, movie});
            if (++count == 5) break;
        }

        return result;
    }
};

/**
 * Example usage:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> shops = obj->search(movie);
 * obj->rent(shop, movie);
 * obj->drop(shop, movie);
 * vector<vector<int>> rented = obj->report();
 */
