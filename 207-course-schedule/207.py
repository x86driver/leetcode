class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        marked = {}
        in_stack = {}

        DG = [[] for _ in range(numCourses)]
        for u,v in prerequisites:
            DG[v].append(u)

        def dfs(v):
            in_stack[v] = True
            marked[v] = True

            for w in DG[v]:
                if not w in marked:
                    if dfs(w):
                        return True
                else:
                    if w in in_stack and in_stack[w]:
                        return True

            in_stack[v] = False
            return False

        for v in range(numCourses):
            if not v in marked:
                if dfs(v):
                    return False

        return True
