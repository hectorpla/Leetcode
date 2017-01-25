#include "UDG_node.h"
#include <unordered_map>
#include <stack>
#include <queue>
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

class Solution2 {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        queue<UndirectedGraphNode *> q;
        
        if ( node == NULL ) return NULL;

        q.push(node);
        while (!q.empty()) { // in every loop, new both the parent and the children, a little messy
            UndirectedGraphNode *x = q.front();
            q.pop();

            UndirectedGraphNode *new_node;
            if (nodeMap.find(x) == nodeMap.end()) { // each old node is put in the queue once
                new_node = new UndirectedGraphNode(x->label);
                nodeMap[x] = new_node;
                cout << "*new node " << x->label << ": " << new_node << endl;
            }
            else new_node = nodeMap[x];
            
            for (UndirectedGraphNode *n : x->neighbors) {
                UndirectedGraphNode *temp;
                
                if (nodeMap.find(n) == nodeMap.end()) {
                    temp = new UndirectedGraphNode(n->label);
                    cout << "new node " << n->label << ": " << temp << endl;
                    nodeMap[n] = temp;
                    q.push(n);
                }
                else {
                    temp = nodeMap[n];
                }
                new_node->neighbors.push_back(temp);
            }
        }
        return nodeMap[node];
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

    Solution2 sol;
    UndirectedGraphNode* new_graph = sol.cloneGraph(a);
    cout << endl << endl << "cloned" << endl;
    if ( new_graph ) new_graph->print(new unordered_set<int>());
    return 0;
}