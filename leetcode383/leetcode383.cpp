#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            int cnt1[26] = {0};
            int cnt2[26] = {0};
            for(int i = 0; i < ransomNote.size(); i++){
                cnt1[ransomNote[i] - 'a']++;
            }
            for(int i = 0; i < magazine.size(); i++){
                cnt2[magazine[i] - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(cnt2[i] < cnt1[i]){
                    return false;
                }
            }
            return true;
    
        }
    };