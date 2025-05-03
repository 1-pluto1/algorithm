from collections import Counter
class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        ans = 0
        _sum = sum(nums[: k - 1])
        cnt = Counter(nums[: k - 1])
        for out, _in in zip(nums, nums[k - 1:]):
            _sum += _in
            cnt[_in] += 1
            if len(cnt) >= m:
                ans = max(ans, _sum)
            _sum -= out
            cnt[out] -= 1
            if cnt[out] == 0:
                del cnt[out]
        return ans
 