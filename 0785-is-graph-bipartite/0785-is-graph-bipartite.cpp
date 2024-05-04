#include <vector>

class Solution {
private:
    bool dfs(int node, int col, std::vector<int>& color, std::vector<std::vector<int>>& adj) {
        color[node] = col;
        
        for(auto neighbor : adj[node]) {
            if(color[neighbor] == -1) {
                if(!dfs(neighbor, 1 - col, color, adj)) {
                    return false;
                }
            } else if(color[neighbor] == col) {
                return false;
            }
        }
        
        return true;
    }
public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        int V = graph.size();
        std::vector<int> color(V, -1);
        
        for(int i = 0; i < V; ++i) {
            if(color[i] == -1) {
                if(!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
