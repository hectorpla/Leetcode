#include "UDG_node.h"
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> newMap;
        stack<UndirectedGraphNode *> st;
        UndirectedGraphNode *ret, *cur; 
        
        if ( node == NULL ) return NULL;
        ret = new UndirectedGraphNode(node->label);;
        newMap[node->label] = ret;
        
        st.push(node);
        while ( !st.empty() ) {
            UndirectedGraphNode *x = st.top();
            int label = x->label;
            // cout << label << endl;
            st.pop();
            cur = newMap[label];
            if ( !cur->neighbors.empty() ) {
                continue;
            }
            
            for (auto n : x->neighbors) {
                UndirectedGraphNode *temp;
                if ( newMap.find(n->label) == newMap.end() ) {
                    temp = new UndirectedGraphNode(n->label);
                }
                else temp = newMap[n->label];
                cur->neighbors.push_back(temp);
                newMap[n->label] = temp;
                st.push(n);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    UndirectedGraphNode *a = new UndirectedGraphNode(0);
    UndirectedGraphNode *b = new UndirectedGraphNode(1);
    UndirectedGraphNode *c = new UndirectedGraphNode(2);

    a->neighbors.push_back(b);
    a->neighbors.push_back(c);
    b->neighbors.push_back(c);
    c->neighbors.push_back(c);

    cout << "original" << endl;
    a->print(new unordered_set<int>());

    Solution sol;
    UndirectedGraphNode* new_graph = sol.cloneGraph(NULL);
    cout << endl << endl << "cloned" << endl;
    if ( new_graph ) new_graph->print(new unordered_set<int>());
    return 0;
}