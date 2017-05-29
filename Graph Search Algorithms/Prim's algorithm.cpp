/*
//
// Created by GianfrancoMS on 5/28/2017.
//

#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

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

    void insertBidirectionalEdge(int u, int v, int weight = 1) {
        insertEdge(u, v, weight);
        insertEdge(v, u, weight);
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

    void prim() {
        if (list.size() <= 1)
            return;
        loadUnvisitedNodes();
        priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        int src = list.begin()->first;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            unvisitedNodes[u] = true;
            for (auto i = list[u].begin(); i != list[u].end(); ++i) {
                int v = (*i);
                int weight = weights[make_pair(u, v)];
                if (!unvisitedNodes[v] && ) {

                }
            }
        }
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

int main() {
    AdjacencyList list = AdjacencyList();
    list.insertBidirectionalEdge(1, 2);
    list.insertBidirectionalEdge(2, 5);
    list.insertBidirectionalEdge(5, 4);
    list.printList();
    list.printWeigths();
    cin.get();
    return 0;
}*/
