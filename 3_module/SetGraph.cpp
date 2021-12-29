#include "SetGraph.h"

SetGraph::SetGraph(int vertexCount) : tree(vertexCount) {};

SetGraph::SetGraph(IGraph& graph) : tree(graph.VerticesCount()) {
    for(size_t i = 0; i < graph.VerticesCount(); ++i) {
        for(auto &j : graph.GetNextVertices(i)) {
            tree[i].insert(j);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    tree[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return tree.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for(auto &i : tree[vertex]) {
        result.push_back(i);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for(size_t i = 0; i < VerticesCount(); ++i) {
        if(tree[i].find(vertex) != tree[i].end()) {
            result.push_back(i);
        }
    }
    return result;
}