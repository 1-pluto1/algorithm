#include<bits/stdc++.h>
using namespace std;

// isalnum()
// isalnum() 是 C/C++ 标准库中的一个函数（在 <cctype> 或 <ctype.h> 头文件中），用于检查一个字符是否是字母或数字。它的特性包括：
// 如果字符是字母（a-z, A-Z）或数字（0-9），返回非零值（真）
// 否则返回 0（假）
// 对于 Unicode 字符，标准 isalnum() 可能无法正确识别，需要使用宽字符版本或其他库

class Solution {
    public:
        bool isPalindrome(string s) {
            int left = 0, right = s.size() - 1;
            while (left < right)
            {
                if (!isalnum(s[left])){
                    left ++;
                } else if (!isalnum(s[right]))
                {
                    right --;
                }else if (tolower(s[left]) == tolower(s[right]))
                {
                    left ++;
                    right --;
                } else{
                    return false;
                }
            }
            return true;
        }
    };