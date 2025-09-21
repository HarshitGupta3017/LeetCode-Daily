# Solution for Design Movie Rental System in PY

from typing import List, Tuple
import bisect

class MovieRentingSystem:
    def __init__(self, n: int, entries: List[List[int]]):
        # movie -> sorted list of (price, shop) for available (unrented) copies
        self.availableMovies = {}  # type: dict[int, List[Tuple[int,int]]]
        # movie -> { shop: price }
        self.moviePriceMap = {}    # type: dict[int, dict[int,int]]
        # sorted list of (price, shop, movie) for rented movies
        self.rentedMovies = []     # type: List[Tuple[int,int,int]]

        for shop, movie, price in entries:
            if movie not in self.availableMovies:
                self.availableMovies[movie] = []
            if movie not in self.moviePriceMap:
                self.moviePriceMap[movie] = {}

            # record price mapping
            self.moviePriceMap[movie][shop] = price
            # insert into available list keeping it sorted by (price, shop)
            bisect.insort(self.availableMovies[movie], (price, shop))

    # helper to remove an item from a sorted list (if present)
    def _remove_sorted(self, lst: List[Tuple], item: Tuple):
        i = bisect.bisect_left(lst, item)
        if i < len(lst) and lst[i] == item:
            lst.pop(i)

    # search: return up to 5 cheapest shops that have this movie unrented
    def search(self, movie: int) -> List[int]:
        if movie not in self.availableMovies:
            return []
        arr = self.availableMovies[movie]
        return [shop for price, shop in arr[:5]]

    # rent: mark a movie from a given shop as rented
    def rent(self, shop: int, movie: int) -> None:
        price = self.moviePriceMap[movie][shop]
        # remove from available pool
        self._remove_sorted(self.availableMovies[movie], (price, shop))
        # add to rented pool (sorted by (price, shop, movie))
        bisect.insort(self.rentedMovies, (price, shop, movie))

    # drop: return a rented movie back to available
    def drop(self, shop: int, movie: int) -> None:
        price = self.moviePriceMap[movie][shop]
        # add back to available pool
        if movie not in self.availableMovies:
            self.availableMovies[movie] = []
        bisect.insort(self.availableMovies[movie], (price, shop))
        # remove from rented pool
        self._remove_sorted(self.rentedMovies, (price, shop, movie))

    # report: return up to 5 cheapest currently rented movies as [shop, movie]
    def report(self) -> List[List[int]]:
        return [[shop, movie] for price, shop, movie in self.rentedMovies[:5]]
