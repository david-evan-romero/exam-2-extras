class MinStack {
private:
    stack<int> st;      // normal stack
    stack<int> minSt;   // keeps track of min values

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minSt.empty()) minSt.push(val);
        else minSt.push(std::min(val, minSt.top()));
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
