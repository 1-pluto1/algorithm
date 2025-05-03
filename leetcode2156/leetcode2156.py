class Solution:
    def subStrHash(self, s: str, power: int, mod: int, k: int, hashValue: int) -> str:
        n = len(s)
        # 用秦九韶算法计算 s[n-k:] 的哈希值
        hash = 0
        for i in range(n - 1, n - k - 1, -1):
            hash = (hash * power + (ord(s[i]) & 31)) % mod
        ans = n - k if hash == hashValue else 0
        pk = pow(power, k, mod)
        # 向左滑窗
        for i in range(n - k - 1, -1, -1):
            # 计算新的哈希值
            hash = (hash * power + (ord(s[i]) & 31) - pk * (ord(s[i + k]) & 31)) % mod
            if hash == hashValue:
                ans = i
        return s[ans: ans + k]

