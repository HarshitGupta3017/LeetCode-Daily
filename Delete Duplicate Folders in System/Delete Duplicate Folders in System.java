// Solution for Delete Duplicate Folders in System in JAVA

class Solution {
    static class Node {
        String val = "";
        String subFolder = "";
        Map<String, Node> children = new HashMap<>();
    }

    private Node getNode(String val) {
        Node node = new Node();
        node.val = val;
        return node;
    }

    private void insert(Node root, List<String> path) {
        for (String folder : path) {
            root.children.putIfAbsent(folder, getNode(folder));
            root = root.children.get(folder);
        }
    }

    private String populateNodes(Node root, Map<String, Integer> subFolderMap) {
        List<String> subFolderPaths = new ArrayList<>();
        for (Map.Entry<String, Node> entry : root.children.entrySet()) {
            String sub = populateNodes(entry.getValue(), subFolderMap);
            subFolderPaths.add("(" + entry.getKey() + sub + ")");
        }
        Collections.sort(subFolderPaths);
        StringBuilder sb = new StringBuilder();
        for (String s : subFolderPaths) sb.append(s);
        root.subFolder = sb.toString();
        if (!root.subFolder.isEmpty())
            subFolderMap.put(root.subFolder, subFolderMap.getOrDefault(root.subFolder, 0) + 1);
        return root.subFolder;
    }

    private void removeDuplicates(Node root, Map<String, Integer> subFolderMap) {
        Iterator<Map.Entry<String, Node>> it = root.children.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<String, Node> entry = it.next();
            if (!entry.getValue().subFolder.isEmpty() &&
                subFolderMap.get(entry.getValue().subFolder) > 1) {
                it.remove();
            } else {
                removeDuplicates(entry.getValue(), subFolderMap);
            }
        }
    }

    private void constructResult(Node root, List<String> path, List<List<String>> res) {
        for (Map.Entry<String, Node> entry : root.children.entrySet()) {
            path.add(entry.getKey());
            res.add(new ArrayList<>(path));
            constructResult(entry.getValue(), path, res);
            path.remove(path.size() - 1);
        }
    }

    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        Node root = getNode("/");
        for (List<String> path : paths)
            insert(root, path);
        Map<String, Integer> subFolderMap = new HashMap<>();
        populateNodes(root, subFolderMap);
        removeDuplicates(root, subFolderMap);
        List<List<String>> res = new ArrayList<>();
        constructResult(root, new ArrayList<>(), res);
        return res;
    }
}
