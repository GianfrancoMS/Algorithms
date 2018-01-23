#include <iostream>
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

    void ucs(int u, int v) {
        if (vertices.find(u) == vertices.end() || vertices.find(v) == vertices.end())
            cout << "Invalid input";
        else {
            auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second > b.second;
            };

            auto tempWeights = weights;

            priority_queue < pair < int, int >, vector < pair < int, int >>, decltype(cmp) > priorityQueue(cmp);
            auto firstPair = make_pair(u, 0);
            priorityQueue.push(firstPair);

            while (!priorityQueue.empty()) {
                auto currentPair = priorityQueue.top();
                priorityQueue.pop();

                cout << currentPair.first << " ";

                if (currentPair.first == v)
                    break;

                auto adjacentVertices = vertices[currentPair.first];
                for (auto adjacent: adjacentVertices) {
                    auto edge = make_pair(currentPair.first, adjacent);
                    tempWeights[edge] += currentPair.second;
                    priorityQueue.push(make_pair(adjacent, tempWeights[edge]));
                }
            }
        }
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
    list.insertEdge(1, 2, 10);
    list.insertEdge(1, 3, 8);
    list.insertEdge(2, 4, 9);
    list.insertEdge(3, 4, 6);
    list.ucs(1, 4);
    return 0;
}
