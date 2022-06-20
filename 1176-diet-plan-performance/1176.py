class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        point = 0
        prefix = [0]
        
        for i,v in enumerate(calories):
            prefix.append(prefix[i] + calories[i])
      
        for i in range(len(calories)):
            if (i+k) > len(calories):
                break
            else:
                total = prefix[i+k] - prefix[i]
            if total > upper:
                point += 1
            elif total < lower:
                point -= 1
        
        return point
