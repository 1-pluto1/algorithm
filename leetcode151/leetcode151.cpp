#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string reverseWords(string s) {
            string res = "";    // 结果字符
            int i = 0;              // 用于表示首个非空字符的位置
            int j = s.size() - 1;   // 用于表示最后一个非空字符的位置
            while(i < j && s[i] == ' ')i++;     // 找到首个非空字符
            while(i < j && s[j] == ' ')j--;     // 找到最后一个非空字符
            for(;j >= i;){
                // 逆序反转单词[j+1, k]
                int k = j;      // 标记一个单词的结尾位置
                while(j >= i && s[j] != ' ')j--;    // 找到单词的起点
                res += s.substr(j + 1, k - j);      // 截取单词加到结果上
                if(j >= i)res += ' ';       // 如果非首个单词，之间用空格间隔
                while(j >= i && s[j] == ' ')j--;    // 找到下一个单词的结尾位置
            }
            return res;               
        }
    };
    