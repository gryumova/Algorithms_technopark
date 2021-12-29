#include "ArcGraph.h"

ArcGraph::ArcGraph(IGraph& graph) : vertex(graph.VerticesCount()) {
    for(size_t i = 0; i < vertex; ++i) {
        std::vector<int> tmp = graph.GetNextVertices(i);
        for(auto &it : tmp) {
            edges.push_back(std::make_pair(i, it));
        }
    }
}

int ArcGraph::VerticesCount() const {
    return vertex;
}

void ArcGraph::AddEdge(int from, int to) {
    edges.push_back(std::make_pair(from, to));
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for(auto &i : edges) {
        if (i.first == vertex) {
            result.push_back(i.second);
        }
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for(auto &i : edges) {
        if (i.second == vertex) {
            result.push_back(i.first);
        }
    }
    return result;
}
