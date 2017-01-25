class UnionFind {
public:
    UnionFind(int n, int g) : labels(n), groups(g) {
        root = vector<int>(n, 0);
        for (int i = 0; i < n; i++) root[i] = i;
        size = vector<int>(n, 1);
    }
    
    int find(int cell) {
        int cur = cell;
        while (root[cur] != cur) cur = root[cur];
        return cur;
    }
    
    void merge(int lhs, int rhs) {
        int lroot, rroot, temp;
        lroot = find(lhs);
        rroot = find(rhs);
        if (lroot == rroot) return;
        if (size[lhs] > size[rhs]) {
            temp = root[rroot] = lroot;
            size[lroot] += size[rroot];
        }
        else {
            temp = root[lroot] = rroot;
            size[rroot] += size[lroot];
        }
        groups--;
        cout << "merged " << lhs << " and " << rhs << "(" << temp << "): " << groups + 1 << " -> " << groups << endl;
    }
    
    int getGroups() {
        return groups;
    }
    
private:
    vector<int> root;
    vector<int> size;
    int labels, groups;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;
        
        int islandCells = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') islandCells++;
            }
        }
        // cout << islandCells << endl;
        
        UnionFind uf(m * n, islandCells);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                
                int label = i * n + j;
                cout << "*****" << label << "******" << endl;
                if (i && grid[i-1][j] == '1') uf.merge(label, label - n);
                if (j && grid[i][j-1] == '1') uf.merge(label, label - 1);
                if (j < n - 1 && grid[i][j+1] == '1') uf.merge(label, label + 1);
                if (i < m - 1 && grid[i+1][j] == '1') uf.merge(label, label + n);
            }
        }
        return uf.getGroups();
    }
};