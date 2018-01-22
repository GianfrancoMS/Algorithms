#include <iostream>
#include <vector>
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

    void dfs(int vertex) {
        if (vertices.find(vertex) == vertices.end())
            cout << "Vertex v doesnt exist in the graph";
        else {
            loadUnvisitedVertices();
            dfsUtil(vertex);
        }
    }

    void dfsWithStack(int vertex) {
        if (vertices.find(vertex) == vertices.end())
            cout << "Vertex v doesnt exist in the graph";
        else {
            loadUnvisitedVertices();
            dfsUtilWithStack(vertex);
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

    void dfsUtil(int vertex) {
        unvisitedVertices[vertex] = true;
        cout << vertex << " ";

        auto adjacentVertices = vertices[vertex];
        for (auto adjacent: adjacentVertices) {
            if (!unvisitedVertices[adjacent])
                dfsUtil(adjacent);
        }
    }

    void dfsUtilWithStack(int vertex) {
        stack<int> verticesStack;
        verticesStack.push(vertex);

        while (!verticesStack.empty()) {
            auto currentVertex = verticesStack.top();
            verticesStack.pop();

            if (!unvisitedVertices[currentVertex]) {
                cout << currentVertex << " ";
                unvisitedVertices[currentVertex] = true;
            }

            auto adjacentVertices = vertices[currentVertex];
            for (auto adjacent = adjacentVertices.rbegin(); adjacent != adjacentVertices.rend(); ++adjacent) {
                if (!unvisitedVertices[*adjacent])
                    verticesStack.push(*adjacent);
            }
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
    list.dfs(1);
    cout << endl;
    list.dfsWithStack(1);
    return 0;
}

