#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class DisjointSet{
public:

    DisjointSet()= default;

    ~DisjointSet()= default;

    DisjointSet(const vector<int>&initializer){
        for(auto i=initializer.begin();i!=initializer.end();++i){
            if(parent.find(*i)==parent.end()){
                parent[*i]=*i;
                rank[*i]=0;
            }
        }
    }

    bool exists(int element){
        return parent.find(element) != parent.end();
    }

    bool isSameSet(int x, int y){
        return find(x)==find(y);
    }

    int find(int element){
        //if element doesn't exist in map, return the same element
        if(!exists(element))
            return element;
        else
            return _find(element);
    }

    void _union(int x, int y) {
        if (exists(x) && exists(y)) {
            int xRoot = find(x);
            int yRoot = find(y);
            if (xRoot == yRoot)
                return;
            if (rank[xRoot] > rank[yRoot])
                parent[yRoot] = xRoot;
            else {
                parent[xRoot] = yRoot;
                if (rank[xRoot] == rank[yRoot])
                    rank[yRoot]++;
            }
        }
    }

    void printParents(){
        for(auto i=parent.begin();i!=parent.end();++i)
            cout<< i->first << " : " <<i->second<<endl;
    }

    void printRanks(){
        for(auto i=rank.begin();i!=rank.end();++i)
            cout<< i->first << " : " <<i->second<<endl;
    }

    void insertElement(int element){
        if(!exists(element)){
            parent[element]=element;
            rank[element]=0;
        }
    }

private:
    map<int,int>rank;
    //element -> parent
    map<int,int>parent;

    int _find(int element){
        if(element!=parent[element])
            parent[element]= _find(parent[element]);
        return parent[element];
    }
};

/*
int main(){
    DisjointSet disjointSet=DisjointSet({1,2,4,5});
    disjointSet._union(1,4);
    disjointSet._union(1,5);
    disjointSet._union(5,2);
    cout<<"Parents: "<<endl;
    disjointSet.printParents();
    cout<<endl;
    cout<<"Ranks: "<<endl;
    disjointSet.printRanks();
    return 0;
}
*/
