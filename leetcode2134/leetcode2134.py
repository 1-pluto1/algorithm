from typing import List

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        k = sum(nums)
        if k == 0:
            return 0  # 处理k=0的情况，避免后续索引错误
        nums2 = nums * 2
        _sum = 0
        ans = 0
        for i in range(len(nums2)):
            _sum += nums2[i]
            if i < k - 1:
                continue
            ans = max(_sum, ans)
            _sum -= nums2[i - k + 1]
        return k - ans