class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = (int)T.size();
        vector<int> ans(n, 0);
        std::stack<int> st;            // store indices, temps strictly decreasing

        // scan from right to left
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && T[st.top()] <= T[i]) st.pop();   // discard not warmer
            if (!st.empty()) ans[i] = st.top() - i;                // distance to next warmer
            st.push(i);
        }
        return ans;
    }
};
