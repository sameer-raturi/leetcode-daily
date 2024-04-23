class Solution {
public:
    vector<vector<int>> convertToAdjacencyList(vector<vector<int>>& edges, int n){
        vector<vector<int>> adjacencyList(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v= edges[i][1];
            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u);
        }
        return adjacencyList;
    }

    void bfs(int src, vector<vector<int>> &adjacencyList, vector<int> & level ){
        int n = adjacencyList.size();
        vector<bool>visited(n, false);
        level[src] = 0;
        queue<int>q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<adjacencyList[node].size(); i++){
                int neighbourNode = adjacencyList[node][i];
                if(!visited[neighbourNode]){
                    q.push(neighbourNode);
                    visited[neighbourNode] = true;
                    level[neighbourNode] = level[node] + 1;
                }
            }
        }
    }
    
    pair<int,int> findLastElement(vector<int> &level){
        int maxm = INT_MIN, maxmIndex = -1;
        for(int i=0;i<level.size();i++){
            if(maxm<level[i]){
                maxm=level[i];
                maxmIndex = i;
            }
        }
        return {maxm, maxmIndex};
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>level1(n);
        vector<int>level2(n);
        vector<vector<int>> adjacencyList =  convertToAdjacencyList(edges,n);

        bfs(0, adjacencyList, level1);
        pair<int,int > heightWithNode = findLastElement(level1);
        
        int endPoint1 = heightWithNode.second;

        bfs(endPoint1, adjacencyList, level1);
        heightWithNode = findLastElement(level1);

        int height = heightWithNode.first;
        int endPoint2 = heightWithNode.second;

        bfs(endPoint2, adjacencyList, level2);
        
        if(height%2==0){
            int levelToCheck = height/2;
            for(int i=0;i<n;i++){
                if(level1[i] == levelToCheck && level2[i] == levelToCheck){
                    ans.push_back(i);
                }
            }
        }
        else{
            int levelToCheck1 = height/2;
            int levelToCheck2 = height/2 + 1;
            for(int i=0;i<n;i++){
                if((level1[i] == levelToCheck1  && level2[i] == levelToCheck2) || (level1[i] == levelToCheck2 && level2[i] == levelToCheck1)){
                    ans.push_back(i);
                }
            }

        }

        return ans;        
    }
};