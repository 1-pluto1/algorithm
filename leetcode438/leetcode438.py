from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        cnt_p = Counter(p)
        cnt_s = Counter()
        for right, c in enumerate(s):
            cnt_s[c] += 1
            if right < len(p) - 1:
                continue
            if cnt_s == cnt_p:
                ans.append(right - len(p) + 1)
            cnt_s[s[right - len(p) + 1]] -= 1
        return ans