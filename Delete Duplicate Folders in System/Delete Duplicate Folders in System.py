# Solution for Delete Duplicate Folders in System in PY

class Node:
    def __init__(self, val=""):
        self.val = val
        self.subFolder = ""
        self.children = {}

class Solution:
    def getNode(self, val):
        return Node(val)

    def insert(self, root, path):
        for folder in path:
            if folder not in root.children:
                root.children[folder] = self.getNode(folder)
            root = root.children[folder]

    def populateNodes(self, root, subFolderMap):
        subFolderPaths = []
        for childName, child in root.children.items():
            sub = self.populateNodes(child, subFolderMap)
            subFolderPaths.append(f"({childName}{sub})")
        subFolderPaths.sort()
        root.subFolder = ''.join(subFolderPaths)
        if root.subFolder:
            subFolderMap[root.subFolder] = subFolderMap.get(root.subFolder, 0) + 1
        return root.subFolder

    def removeDuplicates(self, root, subFolderMap):
        keys = list(root.children.keys())
        for key in keys:
            child = root.children[key]
            if child.subFolder and subFolderMap[child.subFolder] > 1:
                del root.children[key]
            else:
                self.removeDuplicates(child, subFolderMap)

    def constructResult(self, root, path, result):
        for childName, child in root.children.items():
            path.append(childName)
            result.append(path[:])
            self.constructResult(child, path, result)
            path.pop()

    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = self.getNode("/")
        for path in paths:
            self.insert(root, path)
        subFolderMap = {}
        self.populateNodes(root, subFolderMap)
        self.removeDuplicates(root, subFolderMap)
        result = []
        self.constructResult(root, [], result)
        return result
