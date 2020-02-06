#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class GraphWithFlow
{
public:
    GraphWithFlow(): numVertices(0){};
    GraphWithFlow(int n);
    void addEdge(int src, int dst, int capacity);
    void EdmonsKarp(int source, int sink);
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

    bool BFS(vector<vector<int>> residualGraph,
        int *predecessor, int src, int dst);
    int minCapacity(vector<vector<int>> residualGraph,
        int *predecessor, int dst);
};

GraphWithFlow::GraphWithFlow(int n):numVertices(n)
{
    adjMatrix.resize(numVertices);
    for(int i = 0; i < numVertices; i++)
    {
        adjMatrix[i].resize(numVertices);
    }
}

void GraphWithFlow::addEdge(int src, int dst, int capacity)
{
    adjMatrix[src][dst] = capacity;
}

void GraphWithFlow::EdmonsKarp(int source, int sink)
{
    // the status of residual graph will be as same as origin adjacency matrix
    vector<vector<int>> residualGraph(adjMatrix);
    int maxFlow = 0;
    int predecessor[numVertices];

    // use BFS to find augmented path
    while(BFS(residualGraph, predecessor, source, sink))
    {
        int min_capacity = minCapacity(residualGraph, predecessor, sink);
        maxFlow += min_capacity;

        // update residual graph
        for(int Y = sink; Y != source; Y = predecessor[Y])
        {
            int X = predecessor[Y];
            residualGraph[X][Y] -= min_capacity;
            residualGraph[Y][X] += min_capacity;
        }
    }

    cout << "Possible max flow = " << maxFlow << endl;
}

bool GraphWithFlow::BFS(vector<vector<int>> residualGraph, int *predecessor, int src, int dst)
{
    int visited[numVertices];
    for(int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
        predecessor[i] = -1;
    }

    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while(!q.empty())
    {
        int temp = q.front();
        for(int j = 0; j < numVertices; j++)
        {
            if(residualGraph[temp][j] != 0 && visited[j] == 0)
            {
                q.push(j);
                visited[j] = 1;
                predecessor[j] = temp;
            }
        }
        q.pop();
    }

    return (visited[dst] == 1); // there is a path from src to dst if dst has been visited
}

int GraphWithFlow::minCapacity(vector<vector<int>> residualGraph, int *predecessor, int dst)
{
    int min = 99999;

    // find the smallest capacity value on path src to dst
    for(int idx = dst; predecessor[idx] != -1; idx = predecessor[idx])
    {
        if(residualGraph[predecessor[idx]][idx] != 0 && residualGraph[predecessor[idx]][idx] < min)
        {
            min = residualGraph[predecessor[idx]][idx];
        }
    }

    return min;
}

int main()
{
    GraphWithFlow g11(6);

    g11.addEdge(0, 1, 9);g11.addEdge(0, 3, 9);
    g11.addEdge(1, 2, 3);g11.addEdge(1, 3, 8);
    g11.addEdge(2, 4, 2);g11.addEdge(2, 5, 9);
    g11.addEdge(3, 2, 7);g11.addEdge(3, 4, 7);
    g11.addEdge(4, 2, 4);g11.addEdge(4, 5, 8);

    g11.EdmonsKarp(0, 5); // find the max flow from vertex(0) to vertex(5)
    return 0;
}
