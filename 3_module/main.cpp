#include "ArcGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "IGraph.h"
#include <iostream>
#include <queue>

void dfs_aux(const IGraph& graph, int vertex, std::vector<bool> &visited, void (*callback)(int)) {
    visited[vertex] = true;
    callback(vertex);

    std::vector<int> children = graph.GetNextVertices(vertex);
    for (auto& child: children) {
        if (!visited[child]) {
            dfs_aux(graph, child, visited, callback);
        }
    }
}

void dfs(const IGraph& graph, void (*callback)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int vertex = 0; vertex < graph.VerticesCount(); ++vertex) {
        if (!visited[vertex]) {
            dfs_aux(graph, vertex, visited, callback);
        }
    }
}

void bfs(const IGraph& graph, void (*callback)(int))
{
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> q;

    for (int vertex = 0; vertex < graph.VerticesCount(); ++vertex) {
        if (!visited[vertex]){

            visited[vertex] = true;
            q.push(vertex);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                callback(v);
                std::vector<int> children = graph.GetNextVertices(v);
                for (auto& child : children) {
                    if (!visited[child]) {
                        visited[child] = true;
                        q.push(child);
                    }
                }
            }
        }
    }
}

int main()
{
    ListGraph graph1(9);

    graph1.AddEdge(0, 1);
    graph1.AddEdge(1, 5);
    graph1.AddEdge(6, 0);
    graph1.AddEdge(1, 2);
    graph1.AddEdge(2, 3);
    graph1.AddEdge(3, 4);
    graph1.AddEdge(4, 2);
    MatrixGraph graph2 = MatrixGraph(graph1);
    ArcGraph graph3 = ArcGraph(graph2);
    SetGraph graph4 = SetGraph(graph3);

    std::cout << "__________________BFS____________________\n";
    bfs(graph1, [](int vertex) { std::cout << vertex << " "; });
    std::cout << "\n";

    bfs(graph2, [](int vertex) { std::cout << vertex << " "; });
    std::cout << "\n";

    bfs(graph3, [](int vertex) { std::cout << vertex << " "; });
    std::cout << "\n";

    bfs(graph4, [](int vertex) { std::cout << vertex << " "; });
    std::cout << "\n";

    std::cout << "__________________DFS____________________\n";
    dfs(graph1, [](int vertex) { std::cout << vertex << " "; });
    std::cout << "\n";

    dfs(graph2, [](int vertex) { std::cout << vertex << " "; });
    std::cout << "\n";

    dfs(graph3, [](int vertex) { std::cout << vertex << " "; });
    std::cout << "\n";

    dfs(graph4, [](int vertex) { std::cout << vertex << " "; });
    std::cout << "\n";
    return 0;
}
