# Definition for a undirected graph node
from collections import deque
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []
    def __str__(self):
        return str(self.label)

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if node is None:
            return None
        mapping = {}
        q = deque([])
        q.append(node)
        while len(q) > 0:
            nd = q.popleft()
            new = UndirectedGraphNode(nd.label)
            mapping[nd.label] = new
            for neighbor in nd.neighbors:
                if neighbor.label not in mapping:
                    q.append(neighbor)
        q.append(node)
        while len(q) > 0:
            print(q)
            nd = q.popleft()
            mapping[nd.label].neighbors = list(map(lambda x: mapping[x.label], nd.neighbors))
            print('node ' + str(nd.label) + ' set')
            for neighbor in nd.neighbors:
                print(neighbor)
                if len(mapping[neighbor.label].neighbors) == 0:
                    q.append(neighbor)
        return mapping[node.label]

n1 = UndirectedGraphNode(1)
n2 = UndirectedGraphNode(2)
n3 = UndirectedGraphNode(3)
n1.neighbors.extend([n2,n3])
n2.neighbors.extend([n3])
n3.neighbors.extend([n3])

sol = Solution()
sol.cloneGraph(n1)

print(n1.neighbors[0].neighbors)