#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

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

    void bfs(int vertex) {
        if (vertices.find(vertex) == vertices.end())
            cout << "Vertex v doesnt exist in the graph";
        else {
            loadUnvisitedVertices();

            queue<int> verticesQueue;
            unvisitedVertices[vertex] = true;
            verticesQueue.push(vertex);

            while (!verticesQueue.empty()) {
                auto currentVertex = verticesQueue.front();
                cout << currentVertex << " ";
                verticesQueue.pop();

                auto adjacentVertices = vertices[currentVertex];
                for (auto adjacent: adjacentVertices) {
                    if (!unvisitedVertices[adjacent]) {
                        unvisitedVertices[adjacent] = true;
                        verticesQueue.push(adjacent);
                    }
                }
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

};

int main() {
    AdjacencyList list = AdjacencyList();
    list.insertVertex(8);
    list.insertEdge(1, 2);
    list.insertEdge(1, 10);
    list.insertEdge(1, 3);
    list.insertEdge(2, 10);
    list.insertEdge(2, 1);
    list.printList();
    list.bfs(2);
    return 0;
}
