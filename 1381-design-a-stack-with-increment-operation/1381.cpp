class CustomStack {
private:
    vector<int> st;
    int maxSize;
public:
    CustomStack(int maxSize) {
        st.reserve(maxSize);
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (st.size() < maxSize) {
            st.push_back(x);
        }
    }

    int pop() {
        if (st.size() > 0) {
            int last = st.back();
            st.pop_back();
            return last;
        } else {
            return -1;
        }
    }

    void increment(int k, int val) {
        int actual = min(static_cast<int>(st.size()), k);
        for (int i = 0; i < actual; ++i) {
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
