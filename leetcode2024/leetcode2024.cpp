#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxConsecutiveAnswers(string answerKey, int k) {
            int ans = 0, left = 0;
            unordered_map<int, int> cnt;
            for (int right = 0; right < answerKey.size(); right ++){
                cnt[answerKey[right]] ++;
                while (cnt['T'] > k && cnt['F'] > k)
                {
                    cnt[answerKey[left]] --;
                    if (cnt[answerKey[left]] == 0) cnt.erase(answerKey[left]);
                    left ++;
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        }
    };