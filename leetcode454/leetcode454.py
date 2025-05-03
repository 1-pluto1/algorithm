class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        hash = dict()
        res = 0
        for i in nums1:
            for j in nums2:
                hash[i + j] = hash.get(i + j, 0) + 1
        for i in nums3:
            for j in nums4:
                if 0 - i - j in hash:
                    res += hash[0 - i - j]
        return res