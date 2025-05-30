class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        res = [-1] * len(nums)
        stack = []
        for i in range(len(nums) * 2):
            while len(stack) > 0 and nums[i % len(nums)] > nums[stack[-1]]:
                res[stack[-1]] = nums[i % len(nums)]
                stack.pop()
            stack.append(i % len(nums))
        return res