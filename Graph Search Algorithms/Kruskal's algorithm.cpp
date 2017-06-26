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

    DisjointSet(const vector<int>&initializer) {
        for (auto i = initializer.begin(); i != initializer.end(); ++i) {
            if (parent.find(*i) == parent.end()) {
                parent[*i] = *i;
                rank[*i] = 0;
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
            int xRoot = find(x);
            int yRoot = find(y);
            if (xRoot == yRoot)
                return;
            if (rank[xRoot] > rank[yRoot])
                parent[yRoot] = xRoot;
            else {
                parent[xRoot] = yRoot;
                if (rank[xRoot] == rank[yRoot])
                    rank[yRoot]++;
            }
        }
    }

    void insertElement(int element) {
        if (!exists(element)) {
            parent[element] = element;
            rank[element] = 0;
        }
    }

private:
    map<int, int>rank;
    //element -> parent
    map<int, int>parent;

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

    void insertVertex(int v) {
        if (list.find(v) == list.end())
            list[v] = set<int>{};
    }

    void insertEdge(int u, int v, int weight = 1) {
        if (list.find(u) != list.end()) {
            list[u].insert(v);
            if (weights.find(make_pair(u, v)) == weights.end())
                weights[make_pair(u, v)] = weight;
        }
        else {
            list[u] = set<int>{ v };
            weights[make_pair(u, v)] = weight;
        }
        insertVertex(v);
    }

    void printList() {
        cout << endl;
        for (auto i = list.begin(); i != list.end(); ++i) {
            cout << i->first << ": ";
            for (auto j = i->second.begin(); j != i->second.end(); ++j)
                cout << *j << " ";
            cout << endl;
        }
    }

    void printWeigths() {
        for (auto i = weights.begin(); i != weights.end(); ++i) {
            cout << i->first.first << " -> " << i->first.second << " = " << i->second << endl;
        }
    }

    void updateWeigth(int u, int v, int weight) {
        auto edge = make_pair(u, v);
        if (weights.find(edge) != weights.end())
            weights[edge] = weight;
    }

    void kruskal() {
        int result = 0;
        set < pair<int, pair<int, int > > > edges;
        for (auto edge : weights)
            edges.insert(make_pair(edge.second,edge.first));
        DisjointSet dset = DisjointSet();
        for (auto temp : list)
            dset.insertElement(temp.first);
        for (auto edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int set_u = dset.find(u);
            int set_v = dset.find(v);
            if (set_u != set_v) {
                cout << u << " - " << v << endl;
                result += edge.first;
                dset._union(set_u, set_v);
            }
        }
        cout << "Weight of MST: " << result << endl;
    }

private:

    map < int, set<int> > list;
    map < pair<int, int>, int > weights;
    map < int, bool > unvisitedNodes;
    void loadUnvisitedNodes() {
        if (!unvisitedNodes.empty())
            unvisitedNodes.clear();
        for (auto i = list.begin(); i != list.end(); ++i) {
            unvisitedNodes[i->first] = false;
        }
    }
};

/*
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
    list.printList();
    list.printWeigths();
    list.kruskal();
    cin.get();
    return 0;
}
*/
