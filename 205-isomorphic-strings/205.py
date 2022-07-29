class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        table_s_t = {}
        table_t_s = {}
        i = 0

        while i < len(s):
            if t[i] in table_t_s and table_t_s[t[i]] != s[i]:
                return False
            table_s_t[s[i]] = t[i]
            table_t_s[t[i]] = s[i]
            i += 1

        new_str = ""

        i = 0
        while i < len(s):
            new_str += table_s_t[s[i]]
            i += 1

        return new_str == t
