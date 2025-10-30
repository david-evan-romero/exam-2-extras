// 239. Sliding Window Maximum
// Time: O(n), Space: O(k)
// Idea: decreasing deque stores indices; front is current window's max.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;                 // stores indices, values decreasing
        vector<int> ans;
        for (int i = 0; i < (int)nums.size(); ++i) {
            // drop indices that fall out of the window [i-k+1, i]
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            // maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
