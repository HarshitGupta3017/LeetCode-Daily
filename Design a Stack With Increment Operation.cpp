class CustomStack {
public:
    int len;
    vector<int> stack;
    vector<int> inc; 
    CustomStack(int maxSize) : len(maxSize) {
        inc.resize(maxSize, 0);  
    }

    void push(int x) {
        if (stack.size() < len) {
            stack.push_back(x);
        }
    }

    int pop() {
        if (stack.empty()) {
            return -1;
        }

        int idx = stack.size() - 1; 
        int result = stack[idx] + inc[idx];

        if (idx > 0) {
            inc[idx - 1] += inc[idx];  
        }

        inc[idx] = 0;
        stack.pop_back();
        return result;
    }

    void increment(int k, int val) {
        int n = min(k, (int)stack.size());
        if (n > 0) {
            inc[n - 1] += val; 
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
