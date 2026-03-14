# Solution for The k-th Lexicographical String of All Happy Strings of Length n in PY

class Solution:
    
    def generateHappyStrings(self, n, k, currentString, result, generatedCount):
        
        # Base Case
        if len(currentString) == n:
            generatedCount[0] += 1
            
            if generatedCount[0] == k:
                result.append("".join(currentString))
            return
        
        for candidateChar in ['a', 'b', 'c']:
            
            if currentString and currentString[-1] == candidateChar:
                continue
            
            currentString.append(candidateChar)
            
            self.generateHappyStrings(n, k, currentString, result, generatedCount)
            
            currentString.pop()

    def getHappyString(self, n: int, k: int) -> str:
        
        generatedCount = [0]
        result = []
        currentString = []
        
        self.generateHappyStrings(n, k, currentString, result, generatedCount)
        
        return result[0] if result else ""
