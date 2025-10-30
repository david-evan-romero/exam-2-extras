class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // max heap: pair<frequency, character>
        priority_queue<pair<int, char>> pq;
        for (auto& p : freq) pq.push({p.second, p.first});

        string result = "";
        pair<int, char> prev = {0, '#'}; // stores the previous used char

        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            result += ch;
            count--;

            // push previous character back if it still has remaining count
            if (prev.first > 0) pq.push(prev);

            // update previous to current
            prev = {count, ch};
        }

        // if valid: result length should match input
        return result.size() == s.size() ? result : "";
    }
};
