class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        temp = [0] * len(nums)
        for i in range(len(nums)):
            temp[(i + k) % len(nums)] = nums[i]
        nums[:] = temp
