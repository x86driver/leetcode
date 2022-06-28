class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        ptr_name = 0
        ptr_typed = 0

        if len(typed) < len(name):
            return False

        while ptr_name < len(name):
            if ptr_typed >= len(typed):
                return False
            if name[ptr_name] == typed[ptr_typed]:
                ptr_name += 1
                ptr_typed += 1
                continue
            else:
                if ptr_typed > 0:
                    if typed[ptr_typed] == typed[ptr_typed-1]:
                        ptr_typed += 1
                        continue
                return False

        while ptr_typed < len(typed):
            if name[ptr_name-1] == typed[ptr_typed]:
                ptr_typed += 1
            else:
                return False

        return True
