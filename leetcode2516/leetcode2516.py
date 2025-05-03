from collections import Counter
class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        cnt = Counter(s)
        if any(cnt[c] < k for c in "abc"):
            return -1
        ans = 0
        left = 0
        for right in range(len(s)):
            cnt[s[right]] -= 1
            while cnt[s[right]] < k:
                cnt[s[left]] += 1
                left += 1
            ans = max(ans, right - left + 1)
        return len(s) - ans