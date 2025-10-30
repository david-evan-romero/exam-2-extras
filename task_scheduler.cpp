class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) freq[t - 'A']++;

        // Find the maximum frequency
        int maxFreq = *max_element(freq.begin(), freq.end());
        // Count how many tasks have that maximum frequency
        int maxCount = count(freq.begin(), freq.end(), maxFreq);

        // Formula:
        // (maxFreq - 1) * (n + 1) gives the full cycles of cooling periods
        // + maxCount adds the last set of highest frequency tasks
        int intervals = (maxFreq - 1) * (n + 1) + maxCount;

        // The result must be at least the total number of tasks
        return max((int)tasks.size(), intervals);
    }
};
