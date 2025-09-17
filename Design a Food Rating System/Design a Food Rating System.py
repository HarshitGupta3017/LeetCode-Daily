# Solution for Design a Food Rating System in PY

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.food_rating = {}  # food -> rating
        self.food_cuisine = {} # food -> cuisine
        
        # cuisine -> heap of (-rating, food)
        self.cuisine_heap = {}
        
        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.food_rating[food] = rating
            self.food_cuisine[food] = cuisine
            if cuisine not in self.cuisine_heap:
                self.cuisine_heap[cuisine] = []
            heapq.heappush(self.cuisine_heap[cuisine], (-rating, food))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine = self.food_cuisine[food]
        self.food_rating[food] = newRating
        # Push the updated rating onto the heap
        heapq.heappush(self.cuisine_heap[cuisine], (-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        heap = self.cuisine_heap[cuisine]
        
        # Pop outdated entries until the top of the heap matches current rating
        while True:
            rating, food = heap[0]
            if -rating == self.food_rating[food]:
                return food
            heapq.heappop(heap)
