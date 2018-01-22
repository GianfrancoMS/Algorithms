#include <iostream>
#include <map>
#include <set>

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

private:

    map<int, set<int> > vertices;

};

int main() {
    AdjacencyList list = AdjacencyList();
    list.insertVertex(8);
    list.insertEdge(1, 2);
    list.insertEdge(1, 10);
    list.insertEdge(1, 3);
    list.insertEdge(2, 10);
    list.printList();
    return 0;
}

