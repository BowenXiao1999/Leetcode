//
// Created by bowen on 2020/8/22.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int> nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int prev = max(0, mid - 1);
            int next = min(n - 1, mid + 1);
            if (nums[prev] <= nums[mid] && nums[next] <= nums[mid])
                return mid;
            else if (nums[next] > nums[mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 3, 1, 2, 3, 4};
    std::cout << s.findPeakElement(a);
}