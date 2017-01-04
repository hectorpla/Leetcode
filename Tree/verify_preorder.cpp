class Solution {
public:
    bool isValidSerialization(string preorder) {
        unordered_map<int, int> nodes;
        stack<int> st;
        stringstream ss(preorder);
        int num;
        bool started = false;
        
        if ( preorder.size() > 1 && preorder[0] == '#' ) return false;
        while ( ss >> num ) {
            if ( st.empty() && started ) return false;
            st.push(num);
            ss.ignore();
            started = true;

            while ( ss.peek() == '#' ) {
                if ( st.empty() ) return false;
                int top = st.top();
                // cout << "pop: ";
                while (nodes[top] == 1) {
                    st.pop();
                    nodes[top] = 0;
                    // cout << top << " ";
                    if ( !st.empty() ) 
                        top = st.top();
                    else break;
                }
                cout << endl;
                if ( !st.empty() ) 
                    nodes[top]++;
                ss.ignore(2);
            }
        }
        if ( !st.empty() ) return false;
        return true;
    }
};