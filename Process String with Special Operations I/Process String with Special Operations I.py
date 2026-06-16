# Solution for Process String with Special Operations I in PY

class Solution:
    def processStr(self, s: str) -> str:

        result = []

        for ch in s:

            if ch == '*':
                if result:
                    result.pop()

            elif ch == '#':
                result += result

            elif ch == '%':
                result.reverse()

            else:
                result.append(ch)

        return ''.join(result)
