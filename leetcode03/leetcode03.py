class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = set()
        n = len(s)
        right, res = -1, 0
        for i in range(n):
            if i != 0:
                count.remove(s[i - 1])
            while right + 1 < n and s[right + 1] not in count:
                count.add(s[right + 1])
                right += 1
            res = max(res, right - i + 1)
        return res