#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int largestRecHist(vector<int> hist) {
	int n = hist.size();
	int maxSqr = 0;

	for (int i = -1; i < n; i++) {
		priority_queue<int, vector<int>, greater<int> > heap;

		for (int j = i + 1; j < n; j++) {
			heap.push(hist[j]);
			maxSqr = max(maxSqr, (j - i) * heap.top());
			// cout << 
		}
	}
	return maxSqr;
}

int main(int argc, char const *argv[])
{
	int a[] = {2,1,5,6,2,3};
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	cout << largestRecHist(v) << endl;
	return 0;
}