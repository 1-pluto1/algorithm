from collections import defaultdict

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        ans = 0
        cnt = defaultdict(int)
        for x in nums:
            ans += cnt[x]
            cnt[x] += 1
        return ans