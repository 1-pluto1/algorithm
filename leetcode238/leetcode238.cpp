#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        vector<int> post(n, 1);
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = nums[i] * pre[i - 1];
        }
        for (int i = n - 1; i >= 0; i--){
            post[i] = nums[i] * post[i + 1];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = pre[i] * post[i];
        }
        return nums;
    }
};