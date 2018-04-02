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

    void aStar(int vertexBegin, int vertexEnd, map<int, int> heuristic) {
        if (vertices.find(vertexBegin) == vertices.end())
            cout << "Vertex v doesnt exist in the graph";
        else {
            auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second > b.second;
            };

            loadUnvisitedVertices();

            map<int, int> gScore;
            map<int, int> fScore;
            map<int, int> parents;

            for (auto vertex : vertices) {
                gScore[vertex.first] = numeric_limits<int>::max();
                fScore[vertex.first] = numeric_limits<int>::max();
                parents[vertex.first] = -1;
            }

            gScore[vertexBegin] = 0;
            fScore[vertexBegin] = heuristic[vertexBegin];

            priority_queue<pair<int, int>, vector<pair<int, int >>, decltype(cmp)> priorityQueue(cmp);

            auto firstPair = make_pair(vertexBegin, fScore[vertexBegin]);
            priorityQueue.push(firstPair);

            while (!priorityQueue.empty()) {
                auto currentPair = priorityQueue.top();

                int currentVertex = currentPair.first;
                int currentDistance = currentPair.second;

                if (currentVertex == vertexEnd)
                    break;

                priorityQueue.pop();
                unvisitedVertices[currentVertex] = true;

                auto adjacentVertices = vertices[currentVertex];
                for (auto adjacent : adjacentVertices) {

                    if (unvisitedVertices[adjacent])
                        continue;

                    int tentativeGScore = gScore[currentVertex] + weights[make_pair(currentVertex, adjacent)];

                    if (tentativeGScore <= gScore[adjacent]) {
                        parents[adjacent] = currentVertex;
                        gScore[adjacent] = tentativeGScore;
                        fScore[adjacent] = tentativeGScore + heuristic[adjacent];
                        priorityQueue.push(make_pair(adjacent, fScore[adjacent]));
                    }
                }
            }

            printSolution(vertexBegin, vertexEnd, gScore, parents);
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

    void printSolution(int start, int end, map<int, int> distances, map<int, int> parents) {
        cout << start << "->" << end << " = " << distances[end] << " -> "
             << start << " ";
        printPath(parents, end);
        cout << endl;
    }

};

int main() {
    AdjacencyList list = AdjacencyList();
    list.insertBidirectionalEdge(1, 2, 3);
    list.insertBidirectionalEdge(1, 3, 1);
    list.insertBidirectionalEdge(1, 4, 2);

    list.insertBidirectionalEdge(5, 2, 4);
    list.insertBidirectionalEdge(5, 3, 2);
    list.insertBidirectionalEdge(5, 4, 2);

    map<int, int> heuristic;
    heuristic[1] = 2;
    heuristic[2] = 4;
    heuristic[3] = 1;
    heuristic[4] = 2;
    heuristic[5] = 0;

    high_resolution_clock::time_point start = high_resolution_clock::now();
    list.aStar(1, 5, heuristic);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << duration;

    return 0;
}

