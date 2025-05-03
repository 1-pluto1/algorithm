class Solution:
    def reverseWords(self, s: str) -> str:
        res = ""    # 结果字符
        i = 0              # 用于表示首个非空字符的位置
        j = len(s) - 1   # 用于表示最后一个非空字符的位置
        while i < j and s[i] == ' ': i += 1    # 找到首个非空字符
        while i < j and s[j] == ' ': j -= 1    # 找到最后一个非空字符
        while i <= j:
            # 逆序反转单词[j+1, k]
            k = j      # 标记一个单词的结尾位置
            while j >= i and s[j] != ' ': j -= 1    # 找到单词的起点
            res += s[j+1: k+1]      # 截取单词加到结果上
            if j >= i: res += ' '       # 如果非首个单词，之间用空格间隔
            while j >= i and s[j] == ' ': j -= 1    # 找到下一个单词的结尾位置
        return res 
