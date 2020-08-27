//
// Created by bowen on 2020/8/27.
//
#include <iostream>

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int lb = std::max(0, m - 1);
            int rb = std::min(n, m + 1);

            if (nums[m] >= nums[rb] && nums[m] >= nums[lb]) return m;
            else if (nums[m] < nums[rb]) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }
};