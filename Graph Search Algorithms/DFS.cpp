#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
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
        loadNodes();
        cout << endl;
        for (auto i = unvisitedNodes.begin(); i != unvisitedNodes.end(); ++i)
            cout << i->first << " ";
        cout<<endl;
    }

    void dfs(int v){
        if(list.find(v)==list.end())
            cout<<"Inorrect vertex"<<endl;
        else{
            loadNodes();
            dfsUtil(v);
        }
    }

    void dfsWithStack(int v){
        if(list.find(v)==list.end())
            cout<<"Incorrect vertex"<<endl;
        else{
            loadNodes();
            dfsUtilWithStack(v);
        }
    }

private:
    map < int, set<int> >list;
    map < int, bool > unvisitedNodes;

    void dfsUtil(int v){
        unvisitedNodes[v]=true;
        cout<<v<<" ";
        for(auto i=list[v].begin(); i!=list[v].end();++i){
            if(!unvisitedNodes[*i])
                dfsUtil(*i);
        }
    }

    void dfsUtilWithStack(int v){
        stack<int>stack;
        stack.push(v);
        while(!stack.empty()){
            v=stack.top();
            stack.pop();
            if(!unvisitedNodes[v]){
                cout<<v<<" ";
                unvisitedNodes[v]=true;
            }
            for(auto i=list[v].rbegin();i!=list[v].rend();++i){
                if(!unvisitedNodes[*i])
                    stack.push(*i);
            }
        }
    }

    void loadNodes(){
        if(!unvisitedNodes.empty())
            unvisitedNodes.clear();
        for(auto i=list.begin();i!=list.end();++i){
            unvisitedNodes[i->first]=false;
        }
    }

};

/*
int main(){
    AdjacencyList list = AdjacencyList();
    list.insertVertex(8);
    list.insertEdge(1, 2);
    list.insertEdge(1, 10);
    list.insertEdge(1, 3);
    list.insertEdge(2, 10);
    list.insertEdge(2,1);
    list.printList();
    list.dfs(1);
    cout<<endl;
    list.dfsWithStack(1);
    cin.get();
    return 0;
}*/

