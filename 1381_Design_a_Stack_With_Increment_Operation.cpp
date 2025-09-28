#include <bits/stdc++.h>
using namespace std;

class CustomStack {
private:
    vector<int> st, inc;
    int maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (st.size() < maxSize) {
            st.push_back(x);
            inc.push_back(0);
        }
    }

    int pop() {
        if (st.empty()) return -1;

        int i = st.size() - 1;
        int res = st[i] + inc[i];

        if (i > 0) inc[i - 1] += inc[i];
        st.pop_back();
        inc.pop_back();

        return res;
    }

    void increment(int k, int val) {
        int n = st.size();
        if (n == 0) return;
        int idx = min(k, n) - 1;
        inc[idx] += val;
    }
};