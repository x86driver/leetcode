class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        vowel = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
        counter = 1
        ans = ""
        for sen in sentence.split():
            if sen[0] in vowel:
                ans += sen
                ans += "ma"
                ans += "a" * counter
            else:
                ans += sen[1:]
                ans += sen[0]
                ans += "ma"
                ans += "a" * counter

            counter += 1
            ans += " "

        return ans[0:len(ans)-1]
