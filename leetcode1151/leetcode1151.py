# 题目可见：https://leetcode.doocs.org/lc/1151/


class Solution:
    def minSwaps(self, data: List[int]) -> int:
        k = sum(data)
        ans = 0
        _sum = sum(data[:k])
        ans = max(ans, _sum)
        for i in range(k, len(data)):
            _sum += data[i] - data[i - k]
            ans = max(ans, _sum)
        return k - ans

