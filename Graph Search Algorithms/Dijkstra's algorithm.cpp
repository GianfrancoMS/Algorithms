#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <functional>
#include <limits>
#include <chrono>

using namespace std;
using namespace std::chrono;

class AdjacencyList {
public:

    AdjacencyList() = default;

    ~AdjacencyList() = default;

    void insertVertex(int vertex) {
        if (vertices.find(vertex) == vertices.end())
            vertices[vertex] = set<int> {};
    }

    void insertEdge(int u, int v, int weight = 1) {
        if (vertices.find(u) != vertices.end()) {
            vertices[u].insert(v);
            if (weights.find(make_pair(u, v)) == weights.end())
                weights[make_pair(u, v)] = weight;
        } else {
            vertices[u] = set<int> {v};
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
            map<int, int> parents;

            for (auto vertex : vertices) {
                distances[vertex.first] = numeric_limits<int>::max();
                parents[vertex.first] = -1;
            }

            distances[vertex] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int >>, decltype(cmp)> priorityQueue(cmp);

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
                            parents[adjacent] = currentVertex;
                            distances[adjacent] = distances[currentVertex] + currentWeight;
                            priorityQueue.push(make_pair(adjacent, distances[adjacent]));
                        }
                    }
                }
            }

            printSolution(vertex, distances, parents);
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

    void printPath(map<int, int> parents, int vertex) {
        if (parents[vertex] == -1)
            return;

        printPath(parents, parents[vertex]);
        cout << vertex << " ";
    }

    void printSolution(int source, map<int, int> distances, map<int, int> parents) {
        for (auto vertex: vertices) {
            if (vertex.first != source) {
                cout << source << "->" << vertex.first << " = " << distances[vertex.first] << " -> "
                     << source << " ";
                printPath(parents, vertex.first);
                cout << endl;
            }
        }
    }


};

int main() {
    AdjacencyList list = AdjacencyList();
    list.insertEdge(1, 2, 5);
    list.insertEdge(1, 3, 5);
    list.insertEdge(1, 4, 5);
    list.insertEdge(2, 3, 5);
    list.insertEdge(2, 5, 5);
    list.insertEdge(2, 6, 5);
    list.insertEdge(3, 4, 5);
    list.insertEdge(3, 5, 5);
    list.insertEdge(3, 8, 5);
    list.insertEdge(4, 8, 5);
    list.insertEdge(5, 6, 5);
    list.insertEdge(5, 7, 5);
    list.insertEdge(5, 8, 5);
    list.insertEdge(6, 7, 5);
    list.insertEdge(6, 9, 5);
    list.insertEdge(7, 8, 5);
    list.insertEdge(7, 9, 5);
    list.insertEdge(7, 10, 5);
    list.insertEdge(7, 11, 5);
    list.insertEdge(8, 11, 5);
    list.insertEdge(9, 11, 5);
    list.insertEdge(11, 10, 5);

    high_resolution_clock::time_point start = high_resolution_clock::now();
    list.dijkstra(1);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << duration;

    return 0;
}

