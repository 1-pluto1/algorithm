#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n;
    vector<int> nums(n);
    vector<int> preSum(n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        sum += nums[i];
        preSum[i] = sum;
    }

    while (cin >> a >> b)
    {
        int res = 0;
        if (a == 0) res = preSum[b];
        else res = preSum[b] - preSum[a - 1];
        cout << res << endl;
    }
    
}