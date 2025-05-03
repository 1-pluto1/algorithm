from collections import Counter
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)
        if n1 > n2:
            return False
        c_s1 = Counter(s1)
        c_s2 = Counter(s2[:n1])
        if c_s1 == c_s2:
            return True
        for i in range(n1, n2):
            c_s2[s2[i]] += 1
            c_s2[s2[i - n1]] -= 1
            if c_s2[s2[i - n1 + 1]] == 0:
                c_s2.pop(s2[i - n1])
            if c_s1 == c_s2:
                return True
        return False
