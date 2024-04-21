class Solution {
public:
    void initializeRoot(vector<int>& root) {
        for (int i = 0; i < root.size(); i++) {
            root[i] = i;
        }
    }

    int findRoot(int v, vector<int>& root) {
        if (v == root[v])
            return v;

        return root[v] = findRoot(root[v], root);
    }

    void makeUnion(int u, int v, vector<int>& root) { 
        root[findRoot(v, root)] = findRoot(u, root);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> root(n);
        initializeRoot(root);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (findRoot(u, root) != findRoot(v, root)) {
                makeUnion(u, v, root);
            }
        }

        return findRoot(source, root) == findRoot(destination, root);
    }
};