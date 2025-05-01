// Solution for Maximum Number of Tasks You Can Assign in JAVA

class Solution {

    private void removeWorker(TreeMap<Integer, Integer> map, int value) {
        if (map.get(value) == 1) {
            map.remove(value);
        } else {
            map.put(value, map.get(value) - 1);
        }
    }

    private boolean check(int[] tasks, int[] workers, int pills, int strength, int mid) {
        int pillsUsed = 0;
        TreeMap<Integer, Integer> workerMap = new TreeMap<>();
        for (int i = 0; i < mid; i++) {
            workerMap.put(workers[workers.length - 1 - i], 
                          workerMap.getOrDefault(workers[workers.length - 1 - i], 0) + 1);
        }
        for (int i = mid - 1; i >= 0; i--) {
            int req = tasks[i];
            Integer strongestWorker = workerMap.lastKey();
            if (strongestWorker >= req) {
                removeWorker(workerMap, strongestWorker);
            } else if (pillsUsed >= pills) {
                return false;
            } else {
                Integer weakestWorker = workerMap.ceilingKey(req - strength);
                if (weakestWorker == null) {
                    return false;
                }
                removeWorker(workerMap, weakestWorker);
                pillsUsed++;
            }
        }
        return true;
    }

    public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
        int l = 0, r = Math.min(tasks.length, workers.length), res = 0;
        Arrays.sort(tasks);
        Arrays.sort(workers);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(tasks, workers, pills, strength, mid)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
}
