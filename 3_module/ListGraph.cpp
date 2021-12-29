#include "ListGraph.h"

ListGraph::ListGraph(int vertexCount) : vertices(vertexCount) {}

ListGraph::ListGraph(IGraph &graph) : vertices(graph.VerticesCount()) {
  for (int i = 0; i < vertices.size(); i++) {
    vertices[i] = graph.GetNextVertices(i);
  }
}

void ListGraph::AddEdge(int from, int to) { vertices[from].push_back(to); }

int ListGraph::VerticesCount() const { return vertices.size(); }

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
  std::vector<int> result(vertices[vertex].begin(), vertices[vertex].end());
  return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
  std::vector<int> result;

  for (int parent = 0; parent < vertices.size(); parent++) {
    for (auto &child : vertices[parent]) {
      if (child == vertex) {
        result.push_back(parent);
        break;
      }
    }
  }

  return result;
}
