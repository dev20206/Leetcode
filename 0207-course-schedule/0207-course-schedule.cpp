#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build the graph and calculate indegrees
        for (const auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        // Initialize a queue to perform topological sorting
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform topological sorting
        int coursesTaken = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            coursesTaken++;

            for (int neighbor : graph[course]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return coursesTaken == numCourses;
    }
};
