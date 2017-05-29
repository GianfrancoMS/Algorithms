/*
//
// Created by GianfrancoMS on 5/13/2017.
//

#include <iostream>
#include <map>
#include <set>

using namespace std;

class AdjacencyList {
public:

    AdjacencyList() = default;

    ~AdjacencyList() = default;

    void insertVertex(int v) {
        if (list.find(v) == list.end())
            list[v]=set<int>{};
    }

    void insertEdge(int u, int v) {
        if (list.find(u) != list.end())
            list[u].insert(v);
        else
            list[u] = set<int>{ v };
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
    
private:
    map < int, set<int> > list;
};


int main(){
    AdjacencyList list = AdjacencyList();
    list.insertVertex(8);
    list.insertEdge(1, 2);
    list.insertEdge(1, 10);
    list.insertEdge(1, 3);
    list.insertEdge(2, 10);
    list.printList();
    cin.get();
    return 0;
}

*/
