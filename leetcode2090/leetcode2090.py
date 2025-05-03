class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        avgs = [-1] * len(nums)
        _sum = 0
        for i, num in enumerate(nums):
            _sum += num

            if i < 2 * k:
                continue
            avgs[i - k] = _sum // (2 * k + 1)

            _sum -= nums[i - 2 * k]
        return avgs