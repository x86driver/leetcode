class Solution:
    def reverse(self, s, start, end):
        head = start
        tail = end
        while head < tail:
            tmp = s[head]
            s[head] = s[tail]
            s[tail] = tmp
            head += 1
            tail -= 1
        
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        
        head = 0
        tail = len(s) - 1
        
        while head < tail:
            tmp = s[head]
            s[head] = s[tail]
            s[tail] = tmp
            head += 1
            tail -= 1
        

        start = 0
        for i in range(len(s)):
            if s[i] == ' ':
                self.reverse(s, start, i-1)
                start = i+1
                continue
        self.reverse(s, start, len(s)-1)
        
        return s
