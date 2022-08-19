class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        table_target = Counter(target)
        table_arr = Counter(arr)

        for x in table_arr:
            if table_target[x] != table_arr[x]:
                return False

        return True
