#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 暴力解法
// class Solution {
// public:
//     int trap(vector<int>& height) {
//            int n = height.size();
//            if(n == 0) return 0;
//            vector<int> leftMax(n);
//            leftMax[0] = height[0];
//            for(int i = 1; i < n; i++){
//             leftMax[i] = max(leftMax[i - 1], height[i]);
//            }

//            vector<int> rightMax(n);
//            rightMax[n - 1] = height[n - 1];
//            for(int i = n - 2; i > -1; i--){
//             rightMax[i] = max(rightMax[i + 1], height[i]);
//            }

//            int res = 0;
//            for(int i = 0; i < n; i++){
//             res += min(leftMax[i], rightMax[i]) - height[i];
//            }
//            return res;
//     }
// };

// 单调栈

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        stack<int> st;
        st.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++){
            if (height[i] < height[st.top()]){
                st.push(i);
            }
            if (height[i] == height[st.top()]){
                st.pop();
                st.push(i);
            }
            if (height[i] > height[st.top()]){
                while (!st.empty() && height[i] > height[st.top()])
                {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()){
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        sum += h * w;
                    }
                }
                st.push(i);
            }
            
        }
        return sum;
    }
};
