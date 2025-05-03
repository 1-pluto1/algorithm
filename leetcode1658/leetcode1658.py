from collections import defaultdict

class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target = sum(nums) - x
        if target < 0:
            return -1
        left = 0
        temp = 0
        ans = -float('inf')
        for right in range(len(nums)):
            temp += nums[right]
            while temp > target:
                temp -= nums[left]
                left += 1
            if temp == target:
                ans = max(ans, right - left + 1)
        return -1 if ans < 0 else len(nums) - ans