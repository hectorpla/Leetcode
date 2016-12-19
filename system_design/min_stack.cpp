#include <iostream>

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
} Node;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        head = NULL;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        if ( head == NULL ) {
            head = temp;
        }
        temp->next = head;
        head = temp;
        
    }
    
    void pop() {
        if ( !head ) return;
        Node* temp = head;
        head = temp->next;
        delete temp;
    }
    
    int top() {
        if ( !head ) return 0;
        return head->val;
    }
    
    int getMin() {
        int min_val = head ? head->val : 0;
        Node* cur = head;

        while ( cur ) {
            min_val = std::min(cur->val, min_val);
            cur = cur->next;
        }
        return min_val;
    }
    
private:
    Node* head;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
using namespace std;

int main(int argc, char const *argv[])
{
    MinStack ms;
    for (int i = 0; i < 10; ++i)
    {
     ms.push(i*i);
    }

    cout << ms.getMin() << endl;
    return 0;
}