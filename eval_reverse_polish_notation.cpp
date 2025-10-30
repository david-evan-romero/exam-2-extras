class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<long long> st; // use long long to avoid UB on intermediate mult
        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long c = 0;
                if (t == "+") c = a + b;
                else if (t == "-") c = a - b;
                else if (t == "*") c = a * b;
                else /* t == "/" */ c = a / b; // truncates toward zero in C++
                st.push(c);
            } else {
                st.push(stoll(t)); // handles negatives too
            }
        }
        return (int)st.top();
    }
};
