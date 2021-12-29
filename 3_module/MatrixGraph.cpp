#include "MatrixGraph.h"
#include <iostream>


MatrixGraph::MatrixGraph(int vertexCount) : matrix(vertexCount) {
    for(size_t i = 0; i < vertexCount; ++i) {
        for(size_t j = 0; j < vertexCount; ++j) {
            matrix[i].push_back(false);
        }
    }
}

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

void MatrixGraph::AddEdge(int from, int to) {
    matrix[from][to] = true;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for(size_t i = 0; i < VerticesCount(); ++i) {
        if (matrix[vertex][i] == true) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for(size_t i = 0; i < VerticesCount(); ++i) {
        if (matrix[i][vertex] == true) {
            result.push_back(i);
        }
    }
    return result;
}

MatrixGraph::MatrixGraph(IGraph& graph) : matrix(graph.VerticesCount()) {
    for(auto &i : matrix) {
        i.resize(graph.VerticesCount());
    }
    for(size_t i = 0; i < VerticesCount(); ++i) {
        std::vector<int> v = graph.GetNextVertices(i);
        for(auto j: v) {
            matrix[i][j] = true;
        }
    }

}