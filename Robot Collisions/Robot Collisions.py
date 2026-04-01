# Solution for Robot Collisions in PY

class Solution:
    def survivedRobotsHealths(self, pos, health, dir):
        idx = sorted(range(len(pos)), key=lambda i: pos[i])
        stack = []

        for i in idx:
            if dir[i] == 'R':
                stack.append(i)
            else:
                while stack and health[i] > 0:
                    j = stack.pop()
                    if health[j] > health[i]:
                        health[j] -= 1
                        health[i] = 0
                        stack.append(j)
                    elif health[j] < health[i]:
                        health[i] -= 1
                        health[j] = 0
                    else:
                        health[i] = health[j] = 0

        return [h for h in health if h > 0]
