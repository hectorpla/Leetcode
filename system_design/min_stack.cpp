#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    
    }
    
    void push(int x) {
       st.push(x);
       if (minStack.empty()) minStack.push(x);
       else minStack.push(min(x, minStack.top()));
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
    
private:
    stack<int> st;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


int main(int argc, char const *argv[])
{
    MinStack ms;
    cout << "pusing " << -2 << endl;
    ms.push(-2);
    cout << "pusing " << 0 << endl;
    ms.push(0);
    cout << "pusing " << -3 << endl;
    ms.push(-3);
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;

    return 0;
}