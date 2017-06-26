#include <iostream>
#include <map>
#include <set>
#include <queue>

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

    void ucs(int u, int v){
        if(list.find(u)==list.end() || list.find(v)==list.end())
            cout<<"Incorrect vertex";
        else{
            auto cmp=[](const pair<int,int>&a,const pair<int,int>&b){
                return a.second > b.second;
            };
            auto tempWeights=weights;
            priority_queue< pair<int,int>, vector<pair<int,int>>, decltype(cmp) > priorityQueue(cmp);
            auto tempPair = make_pair(u,0);
            priorityQueue.push(tempPair);
            while(!priorityQueue.empty()){
                auto current = priorityQueue.top();
                priorityQueue.pop();
                cout<<current.first<<" ";
                if(current.first==v)
                    break;
                for(auto i=list[current.first].begin();i!=list[current.first].end();++i){
                    auto edge = make_pair(current.first,*i);
                    tempWeights[edge]+=current.second;
                    priorityQueue.push(make_pair(*i,tempWeights[edge]));
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

/*
int main() {

    AdjacencyList list = AdjacencyList();
    list.insertEdge(1, 2, 10);
    list.insertEdge(1, 3, 8);
    list.insertEdge(2, 4, 9);
    list.insertEdge(3, 4, 6);
    list.ucs(1,4);
    list.printList();
    list.printWeigths();
    cin.get();
    return 0;
}*/
