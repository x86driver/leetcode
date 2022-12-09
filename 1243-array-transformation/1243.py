class Solution:
    def transformArray(self, arr: List[int]) -> List[int]:
        table = {}
        while True:
            table = {}
            for i in range(1, len(arr) - 1):
                if arr[i-1] < arr[i] > arr[i+1]:
                    table[i] = arr[i] - 1
                elif arr[i-1] > arr[i] < arr[i+1]:
                    table[i] = arr[i] + 1

            if not table:
                break

            for k,v in table.items():
                arr[k] = v

        return arr
