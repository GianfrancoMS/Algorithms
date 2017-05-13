//
// Created by GianfrancoMS on 5/13/2017.
//

/*
#include <iostream>
#include <vector>
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

    void printUnvisitedNodes(){
        loadUnvisitedNodes();
        cout << endl;
        for (auto i = unvisitedNodes.begin(); i != unvisitedNodes.end(); ++i)
            cout << i->first << " ";
        cout<<endl;
    }

    void bfs(int v){
        if(list.find(v)==list.end())
            cout<<"Incorrect vertex";
        else{
            loadUnvisitedNodes();
            queue<int>myQueue;
            unvisitedNodes[v]=true;
            myQueue.push(v);
            while(!myQueue.empty()){
                v = myQueue.front();
                cout<<v<<" ";
                myQueue.pop();
                for(auto i=list[v].begin();i!=list[v].end();++i){
                    if(!unvisitedNodes[*i]){
                        unvisitedNodes[*i]=true;
                        myQueue.push(*i);
                    }
                }
            }
        }
    }

private:
    map < int, set<int> >list;

    map < int, bool > unvisitedNodes;

    void loadUnvisitedNodes(){
        if(!unvisitedNodes.empty())
            unvisitedNodes.clear();
        for(auto i=list.begin();i!=list.end();++i){
            unvisitedNodes[i->first]=false;
        }
    }

};

int main(){
    AdjacencyList list = AdjacencyList();
    list.insertVertex(8);
    list.insertEdge(1, 2);
    list.insertEdge(1, 10);
    list.insertEdge(1, 3);
    list.insertEdge(2, 10);
    list.insertEdge(2,1);
    list.printList();
    list.bfs(2);
    cin.get();
    return 0;
}*/
