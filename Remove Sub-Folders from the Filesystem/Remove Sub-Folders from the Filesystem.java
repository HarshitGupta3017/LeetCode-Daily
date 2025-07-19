// Solution for Remove Sub-Folders from the Filesystem in JAVA

class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> res = new ArrayList<>();
        for (String f : folder) {
            if (res.isEmpty() || !f.startsWith(res.get(res.size() - 1) + "/"))
                res.add(f);
        }
        return res;
    }
}
