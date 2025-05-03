# 题目可见：https://leetcode.doocs.org/lc/2107/

from collections import Counter
class Solution:
    def shareCandies(self, candies: List[int], k: int) -> int:
        ans = 0
        cnt = Counter(candies[k:])
        ans = max(ans, len(cnt))
        for i in range(k, len(candies)):
            cnt[candies[i - k]] += 1
            cnt[candies[i]] -= 1
            if cnt[candies[i]] == 0:
                cnt.pop(candies[i])
            ans = max(ans, len(cnt))
        return ans 