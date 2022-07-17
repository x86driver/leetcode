class Solution:
    def isSame(self, sensor1, sensor2, p1, p2):
        while p1 < len(sensor1) and p2 < len(sensor2):
            if sensor1[p1] != sensor2[p2]:
                return -1

            p1 += 1
            p2 += 1

        return 0

    def badSensor(self, sensor1: List[int], sensor2: List[int]) -> int:
        ptr1 = 0
        ptr2 = 0

        while ptr1 < len(sensor1) and ptr2 < len(sensor2):
            if sensor1[ptr1] == sensor2[ptr2]:
                ptr1 += 1
                ptr2 += 1
                continue

            if ptr1 == len(sensor1) - 1:
                return -1
            if self.isSame(sensor1, sensor2, ptr1+1, ptr2):
                return 1
            elif self.isSame(sensor1, sensor2, ptr1, ptr2+1):
                return 2
            else:
                return -1

        return -1
