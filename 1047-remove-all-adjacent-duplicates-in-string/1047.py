class Solution:
    def removeDuplicates(self, s: str) -> str:
        if len(s) == 1:
            return s

        buf = list(s)
        pa = 0
        pb = 1
        while pb < len(buf):
            if buf[pa] == buf[pb]:
                del buf[pa]
                del buf[pa]
                if pa > 0:
                    pa -= 1
                    pb -= 1
                continue
            pa += 1
            pb += 1

        return ''.join(buf)
