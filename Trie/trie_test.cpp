#include "Trie.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Trie trie;

	trie.insert("heap");
	trie.insert("hear");
	trie.insert("ink");
	trie.insert("in");

	cout << "if there is a word \"he\": " << trie.search("he") << endl;
	cout << "if there is a word \"heap\": " << trie.search("heap") << endl;
	cout << "if there is a word \"heart\": " << trie.search("heart") << endl;
	cout << "if there is a word \"in\": " << trie.search("in") << endl;
	cout << "if there is a word \"there\": " << trie.search("there") << endl;
	
	cout << "------------------------------------------------------------------------" << endl;
	cout << "if there is a word that starts with \"he\": " << trie.startsWith("he") << endl;
	cout << "if there is a word that starts with \"ink\": " << trie.startsWith("ink") << endl;
	cout << "if there is a word that starts with \"bo\": " << trie.startsWith("bo") << endl;
	cout << endl;
	return 0;
}