class Solution:
    def reformatNumber(self, number: str) -> str:
        digits = ['0','1','2','3','4','5','6','7','8','9']
        num = []
        ans = ""

        for n in number:
            if n in digits:
                num.append(n)

        ptr = 0
        while ptr < len(num):
            if len(num) - ptr > 4:
                ans += num[ptr]
                ptr += 1
                ans += num[ptr]
                ptr += 1
                ans += num[ptr]
                ptr += 1
                ans += "-"
                continue
            if len(num) - ptr == 4:
                ans += num[ptr]
                ptr += 1
                ans += num[ptr]
                ptr += 1
                ans += "-"
                ans += num[ptr]
                ptr += 1
                ans += num[ptr]
                ptr += 1
                continue
            if len(num) - ptr == 3:
                ans += num[ptr]
                ptr += 1
                ans += num[ptr]
                ptr += 1
                ans += num[ptr]
                ptr += 1
                continue
            if len(num) - ptr == 2:
                ans += num[ptr]
                ptr += 1
                ans += num[ptr]
                ptr += 1
                continue

        return ans
