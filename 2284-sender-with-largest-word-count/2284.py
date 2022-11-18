class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        table = {}
        max_len = 0

        for i in range(len(senders)):
            name = senders[i]
            msg_len = len(messages[i].split())
            if name in table:
                table[name] += msg_len
            else:
                table[name] = msg_len
            max_len = max(table[name], max_len)

        names = []
        for name in table:
            if table[name] == max_len:
                names.append(name)

        names.sort(reverse=True)
        return names[0]
