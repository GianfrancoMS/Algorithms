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

    void prim(int v) {
        if (list.find(v) == list.end())
            cout << "Incorrect vertex. Try again";
        else {
            auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second > b.second;
            };
            map<int, int> distances;
            for (auto node : list)
                distances[node.first] = 0x3f3f3f3f;
            distances[v] = 0;
            loadUnvisitedNodes();
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
            auto tempPair = make_pair(v, distances[v]);
            pq.push(tempPair);
            while (!pq.empty()) {
                auto current = pq.top();
                pq.pop();
                int u = current.first;
                int d = current.second;
                unvisitedNodes[u] = true;
                if (distances[u] >= d)
                    for (auto adjacent : list[u]) {
                        if (unvisitedNodes[adjacent])
                            continue;
                        int v = adjacent;
                        int weight = weights[make_pair(u, v)];
                        if (weight < distances[v]) {
                            distances[v] = weight;
                            pq.push(make_pair(v, distances[v]));
                        }
                    }
            }
            for (auto value : distances)
                cout << value.first << " : " << value.second << endl;
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

/*
int main() {
    AdjacencyList list = AdjacencyList();
    list.insertBidirectionalEdge(1, 2);
    list.insertBidirectionalEdge(2, 5);
    list.insertBidirectionalEdge(5, 4);
    list.printList();
    list.printWeigths();
    cin.get();
    return 0;
}
*/
