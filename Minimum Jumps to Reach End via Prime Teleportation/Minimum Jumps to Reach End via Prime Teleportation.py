# Solution for Minimum Jumps to Reach End via Prime Teleportation in PY

class Solution:

    # Sieve of Eratosthenes to identify prime numbers
    def buildSieve(self, maximumValue):

        isPrime = [True] * (maximumValue + 1)

        if maximumValue >= 0:
            isPrime[0] = False

        if maximumValue >= 1:
            isPrime[1] = False

        number = 2

        while number * number <= maximumValue:

            if isPrime[number]:

                multiple = number * number

                while multiple <= maximumValue:

                    isPrime[multiple] = False
                    multiple += number

            number += 1

        return isPrime

    def minJumps(self, nums):

        totalElements = len(nums)

        # Map value -> all indices containing that value
        valueToIndicesMap = defaultdict(list)

        maximumValue = 0

        for index, value in enumerate(nums):

            valueToIndicesMap[value].append(index)

            maximumValue = max(maximumValue, value)

        # Build prime lookup table
        isPrime = self.buildSieve(maximumValue)

        # Standard BFS setup
        bfsQueue = deque([0])

        visited = [False] * totalElements
        visited[0] = True

        # Prevent repeated processing of same prime teleportation
        processedPrimes = set()

        minimumSteps = 0

        while bfsQueue:

            currentLevelSize = len(bfsQueue)

            for _ in range(currentLevelSize):

                currentIndex = bfsQueue.popleft()

                # Reached destination
                if currentIndex == totalElements - 1:
                    return minimumSteps

                # Adjacent Move: Left
                if (currentIndex - 1 >= 0 and
                    not visited[currentIndex - 1]):

                    bfsQueue.append(currentIndex - 1)
                    visited[currentIndex - 1] = True

                # Adjacent Move: Right
                if (currentIndex + 1 < totalElements and
                    not visited[currentIndex + 1]):

                    bfsQueue.append(currentIndex + 1)
                    visited[currentIndex + 1] = True

                currentValue = nums[currentIndex]

                # Skip if current value is not prime
                # OR prime teleportation already processed
                if (not isPrime[currentValue] or
                    currentValue in processedPrimes):

                    continue

                # Prime Teleportation
                multiple = currentValue

                while multiple <= maximumValue:

                    if multiple in valueToIndicesMap:

                        for nextIndex in valueToIndicesMap[multiple]:

                            if not visited[nextIndex]:

                                bfsQueue.append(nextIndex)
                                visited[nextIndex] = True

                    multiple += currentValue

                # Mark this prime as processed
                processedPrimes.add(currentValue)

            minimumSteps += 1

        return -1
