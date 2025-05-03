class Solution:
    def minFlips(self, s: str) -> int:
        length = len(s)
        target = "01"
        cnt = 0
        for i in range(0, length):
            cnt += (s[i] != target[i % 2])
        ans = min(cnt, length - cnt)
        for i in range(0, length):
            cnt -= (s[i] != target[i % 2])
            cnt += (s[i] != target[(i + length) % 2])
            ans = min(ans, cnt, length - cnt)
        return ans