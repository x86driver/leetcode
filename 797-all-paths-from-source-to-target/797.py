class Solution:
    def dfs(self, index, graph):
        self.path.append(index)
        if self.path[-1] == len(graph) - 1:
            self.ans.append(self.path.copy())
            self.path.pop()
            return

        for nodes in graph[index]:
            self.dfs(nodes, graph)
        self.path.pop()

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.path = []
        self.ans = []
        self.dfs(0, graph)

        return self.ans
