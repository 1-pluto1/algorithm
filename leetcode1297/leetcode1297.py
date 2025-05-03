class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        n = len(s)
        occ = collections.defaultdict(int)
        ans = 0
        for i in range(n):
            exist = set()
            cur = ""
            for j in range(i, min(n, i + maxSize)):
                exist.add(s[j])
                if len(exist) > maxLetters:
                    break
                cur += s[j]
                if j - i + 1 >= minSize:
                    occ[cur] += 1
                    ans = max(ans, occ[cur])
        return ans

