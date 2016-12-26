#ifndef UDG_NODE_H
#define UDG_NODE_H 

#include <vector>
#include <iostream>
#include <unordered_set>

struct UndirectedGraphNode {
	int label;
	std::vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};

	void print(std::unordered_set<int>* met) {
		std::cout << label << ": ";
		for (auto n : this->neighbors) {
			std::cout << n->label << " ";
		}
		std::cout << std::endl;
		for (auto n : this->neighbors) {
			if ( met->find(n->label) != met->end() ) continue;
			met->insert(n->label);
			n->print(met);
		}
	}
};
#endif
