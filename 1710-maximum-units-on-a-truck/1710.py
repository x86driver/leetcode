class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1], reverse=True)
        print(boxTypes)

        maxUnits = 0
        for i in range(len(boxTypes)):
            boxes = boxTypes[i][0]
            units = boxTypes[i][1]
            pickup = min(truckSize, boxes)
            if pickup <= 0:
                break
            maxUnits += pickup * units
            truckSize -= pickup

        return maxUnits
