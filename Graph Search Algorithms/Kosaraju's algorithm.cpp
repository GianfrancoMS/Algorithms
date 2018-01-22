#include <iostream>
#include <map>
#include <set>
#include <stack>

using namespace std;

class AdjacencyList {
public:

    AdjacencyList() = default;

    ~AdjacencyList() = default;

    void insertVertex(int vertex) {
        if (vertices.find(vertex) == vertices.end())
            vertices[vertex] = set < int > {};
    }

    void insertEdge(int u, int v) {
        if (vertices.find(u) != vertices.end())
            vertices[u].insert(v);
        else
            vertices[u] = set < int > {v};
        insertVertex(v);
    }

    void printList() {
        for (auto vertex: vertices) {
            cout << vertex.first << ": ";
            for (auto adjacent: vertex.second)
                cout << adjacent << " ";
            cout << endl;
        }
    }

    AdjacencyList getTranspose() {
        AdjacencyList transpose = AdjacencyList();
        for (auto vertex: vertices)
            for (auto adjacent: vertex.second)
                transpose.insertEdge(adjacent, vertex.first);
        return transpose;
    }

    void printConnectedComponents() {
        loadUnvisitedVertices();

        stack<int> verticesStack;
        for (auto vertex: vertices)
            if (!unvisitedVertices[vertex.first])
                fillOrder(vertex.first, verticesStack);

        auto transpose = this->getTranspose();

        loadUnvisitedVertices();

        while (!verticesStack.empty()) {
            int currentVertex = verticesStack.top();
            verticesStack.pop();
            if (!unvisitedVertices[currentVertex]) {
                transpose.DFSUtil(currentVertex);
                cout << endl;
            }
        }
    }

private:

    map<int, set<int> > vertices;

    map<int, bool> unvisitedVertices;

    void loadUnvisitedVertices() {
        if (!unvisitedVertices.empty())
            unvisitedVertices.clear();
        for (auto vertex: vertices) {
            unvisitedVertices[vertex.first] = false;
        }
    }

    void fillOrder(int vertex, stack<int> &verticesStack) {
        unvisitedVertices[vertex] = true;

        auto adjacentVertices = vertices[vertex];
        for (auto adjacent: adjacentVertices)
            if (!unvisitedVertices[adjacent])
                fillOrder(adjacent, verticesStack);

        verticesStack.push(vertex);
    }

    void DFSUtil(int vertex) {
        unvisitedVertices[vertex] = true;
        cout << vertex << " ";

        auto adjacentVertices = vertices[vertex];
        for (auto adjacent: adjacentVertices)
            if (!unvisitedVertices[adjacent])
                DFSUtil(adjacent);
    }

};

int main() {
    AdjacencyList list = AdjacencyList();
    list.insertEdge(1, 2);
    list.insertEdge(1, 10);
    list.insertEdge(1, 3);
    list.insertEdge(2, 10);
    list.insertEdge(2, 1);
    list.printConnectedComponents();
    return 0;
}
