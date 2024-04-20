class Solution {
public:
    int m, n;
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool isValidMove(int x, int y){
        if(x>=0 && y>=0 && x<m && y<n){
            return true;
        }
        return false;
    }


    vector<int> bfs(int x, int y, vector<vector<int>>& land, vector<vector<bool>>& visited) {

        vector<int> landCorners = {x, y, x, y};

        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y]=true;
        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int u = p.first + moves[i].first;
                int v = p.second + moves[i].second;

                if (isValidMove(u, v)) {
                    if (!visited[u][v] && land[u][v]) {
                        cout<<u<<" "<<v<<endl;
                        q.push({u, v});
                        visited[u][v] = true;
                        landCorners[2] = u;
                        landCorners[3] = v;
                    }
                }
            }
        }
        return landCorners;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && land[i][j]) {
                    vector<int> landCorners = bfs(i, j, land, visited);
                    ans.push_back(landCorners);
                }
            }
        }
        return ans;
    }
};