#include <iostream>
#include <map>
#include <set>
#include <stack>

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

    void topologicalSort(){
        loadNodes();
        stack<int>Stack;
        for(auto i=list.begin();i!=list.end();++i)
            if(!unvisitedNodes[i->first])
                topologicalSortUtil(i->first,Stack);
        while(!Stack.empty()){
            cout<<Stack.top()<<" ";
            Stack.pop();
        }
    }

private:
    map < int, set<int> > list;
    map < int, bool > unvisitedNodes;

    void loadNodes(){
        if(!unvisitedNodes.empty())
            unvisitedNodes.clear();
        for(auto i=list.begin();i!=list.end();++i){
            unvisitedNodes[i->first]=false;
        }
    }

    void topologicalSortUtil(int v, stack<int>&Stack){
        unvisitedNodes[v]=true;
        for(auto i=list[v].begin();i!=list[v].end();++i)
            if(!unvisitedNodes[*i])
                topologicalSortUtil(*i,Stack);
        Stack.push(v);
    }
};

/*
int main(){
    AdjacencyList list = AdjacencyList();
    list.insertEdge(1, 2);
    list.insertEdge(1, 10);
    list.insertEdge(1, 3);
    list.insertEdge(2, 10);
    list.insertEdge(2,1);
    list.printList();
    list.topologicalSort();
    return 0;
}*/

