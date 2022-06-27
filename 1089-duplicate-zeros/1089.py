class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        tmp = [None] * len(arr)
        i = 0
        tmp_index = 0
        while i < len(arr):
            if tmp_index >= len(arr):
                break
            tmp[tmp_index] = arr[i]
            tmp_index += 1
            if arr[i] == 0:
                if tmp_index < len(arr):
                    tmp[tmp_index] = 0
                    tmp_index += 1
            i += 1

        for i,v in enumerate(arr):
            arr[i] = tmp[i]
