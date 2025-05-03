// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int balancedString(string s) {
//         unordered_map<char, int> cnt;
//         cnt['Q'] = cnt['W'] = cnt['E'] = cnt['R'] = 0;
//         int n = s.size(), m = n / 4;
//         for (char c : s) {
//             cnt[c]++;
//         }

//         int ans = n, left = 0;
//         for (int right = 0; right < n; right++) {
//             cnt[s[right]]--;  // 当前字符移出窗口（相当于被替换）
//             // 检查窗口外的字符是否都 <= m
//             while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m) {
//                 ans = min(ans, right - left + 1);  // 更新最小窗口
//                 cnt[s[left]]++;  // 恢复左边界字符（缩小窗口）
//                 left++;
//             }
//         }
//         return ans;
//     }
// };

// 我感觉我的代码没错，可能是力扣抽风吧