#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <functional>

using namespace std;

class DisjointSet {
public:

    DisjointSet() = default;

    ~DisjointSet() = default;

    DisjointSet(const vector<int> &initializer) {
        for (auto element: initializer) {
            if (parent.find(element) == parent.end()) {
                parent[element] = element;
                rank[element] = 0;
            }
        }
    }

    bool exists(int element) {
        return parent.find(element) != parent.end();
    }

    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    int find(int element) {
        //if element doesn't exist in map, return the same element
        if (!exists(element))
            return element;
        else
            return _find(element);
    }

    void _union(int x, int y) {
        if (exists(x) && exists(y)) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)
                return;
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootX] = rootY;
                if (rank[rootX] == rank[rootY])
                    rank[rootY]++;
            }
        }
    }

    void printParents() {
        for (auto element: parent)
            cout << element.first << " : " << element.second << endl;
    }

    void printRanks() {
        for (auto element: rank)
            cout << element.first << " : " << element.second << endl;
    }

    void insertElement(int element) {
        if (!exists(element)) {
            parent[element] = element;
            rank[element] = 0;
        }
    }

private:

    map<int, int> rank;

    //element -> parent
    map<int, int> parent;

    int _find(int element) {
        if (element != parent[element])
            parent[element] = _find(parent[element]);
        return parent[element];
    }

};

class AdjacencyList {
public:

    AdjacencyList() = default;

    ~AdjacencyList() = default;

    void insertVertex(int vertex) {
        if (vertices.find(vertex) == vertices.end())
            vertices[vertex] = set < int > {};
    }

    void insertEdge(int u, int v, int weight = 1) {
        if (vertices.find(u) != vertices.end()) {
            vertices[u].insert(v);
            if (weights.find(make_pair(u, v)) == weights.end())
                weights[make_pair(u, v)] = weight;
        } else {
            vertices[u] = set < int > {v};
            weights[make_pair(u, v)] = weight;
        }
        insertVertex(v);
    }

    void insertBidirectionalEdge(int u, int v, int weight = 1) {
        insertEdge(u, v, weight);
        insertEdge(v, u, weight);
    }

    void printList() {
        for (auto vertex: vertices) {
            cout << vertex.first << ": ";
            for (auto adjacent: vertex.second)
                cout << adjacent << " ";
            cout << endl;
        }
    }

    void printWeights() {
        for (auto edge: weights) {
            cout << edge.first.first << " -> " << edge.first.second << " = " << edge.second << endl;
        }
    }

    void updateWeight(int u, int v, int weight) {
        auto edge = make_pair(u, v);
        if (weights.find(edge) != weights.end())
            weights[edge] = weight;
    }

    void kruskal() {
        int result = 0;

        //<weight, pair<u,v>
        set < pair < int, pair < int, int > > > edges;
        for (auto edge : weights)
            edges.insert(make_pair(edge.second, edge.first));

        DisjointSet disjointSet = DisjointSet();
        for (auto vertex : vertices)
            disjointSet.insertElement(vertex.first);

        for (auto edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;

            int setU = disjointSet.find(u);
            int setV = disjointSet.find(v);
            if (setU != setV) {
                cout << u << " - " << v << endl;
                result += edge.first;
                disjointSet._union(setU, setV);
            }
        }

        cout << "Weight of MST: " << result << endl;
    }

private:

    map<int, set<int> > vertices;

    map<int, bool> unvisitedVertices;

    map<pair<int, int>, int> weights;

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
    list.insertEdge(1, 3, 3);
    list.insertEdge(1, 2, 2);
    list.insertEdge(1, 5, 6);
    list.insertEdge(2, 5, 2);
    list.insertEdge(2, 6, 3);
    list.insertEdge(3, 5, 1);
    list.insertEdge(3, 4, 5);
    list.insertEdge(4, 5, 5);
    list.insertEdge(4, 6, 6);
    list.insertEdge(6, 5, 4);
    list.kruskal();
    return 0;
}

