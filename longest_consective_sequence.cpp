#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<long long> s(nums.begin(), nums.end()); // set for O(1) finds
        int best = 0;

        for (long long x : s) {
            // start only at the beginning of a streak
            if (!s.count(x - 1)) {
                long long cur = x;
                int len = 1;
                while (s.count(cur + 1)) {
                    cur++;
                    len++;
                }
                if (len > best) best = len;
            }
        }
        return best;
    }
};
