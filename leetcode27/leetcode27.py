class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slowIndex = 0
        for fastIndex in range(len(nums)):
            if val != nums[fastIndex]:
                nums[slowIndex] = nums[fastIndex]
                slowIndex += 1
        return slowIndex