#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <functional>
#include <limits>

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

    void dijkstra(int vertex) {
        if (vertices.find(vertex) == vertices.end())
            cout << "Vertex v doesnt exist in the graph";
        else {
            auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second > b.second;
            };

            map<int, int> distances;
            for (auto vertex : vertices)
                distances[vertex.first] = numeric_limits<int>::max();
            distances[vertex] = 0;

            priority_queue < pair < int, int >, vector < pair < int, int >>, decltype(cmp) > priorityQueue(cmp);

            auto firstPair = make_pair(vertex, 0);
            priorityQueue.push(firstPair);

            while (!priorityQueue.empty()) {
                auto currentPair = priorityQueue.top();
                priorityQueue.pop();

                int currentVertex = currentPair.first;
                int currentDistance = currentPair.second;

                if (distances[currentVertex] >= currentDistance) {
                    auto adjacentVertices = vertices[currentVertex];
                    for (auto adjacent : adjacentVertices) {
                        int currentWeight = weights[make_pair(currentVertex, adjacent)];

                        if (distances[currentVertex] + currentWeight < distances[adjacent]) {
                            distances[adjacent] = distances[currentVertex] + currentWeight;
                            priorityQueue.push(make_pair(adjacent, distances[adjacent]));
                        }
                    }
                }
            }

            for (auto destination : distances)
                cout << "From vertex " << vertex << " to vertex " << destination.first << " : " << destination.second
                     << endl;
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
    list.dijkstra(1);
    list.printWeights();
    return 0;
}

